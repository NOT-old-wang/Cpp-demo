#include <unistd.h>

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemRepositorySize = 10;
static const int kItemsToProduce = 20;

struct ItemRepository {
  // 产品缓冲区, 配合 read_position 和 write_position 模型环形队列
  int item_buffer[kItemRepositorySize];
  std::size_t read_position;         // 消费者读取产品位置
  std::size_t write_position;        // 生产者写入产品位置
  std::mutex mutex;                  // 互斥量,保护产品缓冲区
  std::condition_variable not_full;  // 条件变量, 指示产品缓冲区不为满
  std::condition_variable not_empty;  // 条件变量, 指示产品缓冲区不为空
} item_repository;

void ProduceItem(ItemRepository *repository, int item) {
  std::unique_lock<std::mutex> lock(repository->mutex);
  if (((repository->write_position + 1) % kItemRepositorySize) ==
         repository->read_position) {  // item buffer is full, just wait here.
    std::cout << "Producer is waiting for an empty slot..." << std::endl;
    (repository->not_full)
        .wait(lock);  // 生产者等待"产品库缓冲区不为满"这一条件发生.
  }

  (repository->item_buffer)[repository->write_position] = item;  // 写入产品.
  (repository->write_position)++;  // 写入位置后移.

  if (repository->write_position ==
      kItemRepositorySize)  // 写入位置若是在队列最后则重新设置为初始位置.
    repository->write_position = 0;

  (repository->not_empty).notify_all();  // 通知消费者产品库不为空.
  lock.unlock();                         // 解锁.
}

int ConsumeItem(ItemRepository *repository) {
  int data;
  std::unique_lock<std::mutex> lock(repository->mutex);
  // item buffer is empty, just wait here.
  if (repository->write_position == repository->read_position) {
    std::cout << "Consumer is waiting for items..." << std::endl;
    (repository->not_empty)
        .wait(lock);  // 消费者等待"产品库缓冲区不为空"这一条件发生.
  }

  data = (repository->item_buffer)[repository->read_position];  // 读取某一产品
  (repository->read_position)++;  // 读取位置后移

  if (repository->read_position >=
      kItemRepositorySize)  // 读取位置若移到最后，则重新置位.
    repository->read_position = 0;

  (repository->not_full).notify_all();  // 通知消费者产品库不为满.
  lock.unlock();                        // 解锁.

  return data;  // 返回产品.
}

// 生产者任务
void ProducerTask() {
  for (int i = 1; i <= kItemsToProduce; ++i) {
    sleep(1);
    std::cout << "Produce the " << i << "^th item..." << std::endl;
    ProduceItem(&item_repository, i);  // 循环生产 kItemsToProduce 个产品.
  }
}

// 消费者任务
void ConsumerTask() {
  static int cnt = 0;
  while (1) {
    sleep(1);
    int item = ConsumeItem(&item_repository);  // 消费一个产品.
    std::cout << "Consume the " << item << "^th item" << std::endl;
    if (++cnt == kItemsToProduce)
      break;  // 如果产品消费个数为 kItemsToProduce, 则退出.
  }
}

void InitItemRepository(ItemRepository *repository) {
  repository->write_position = 0;  // 初始化产品写入位置.
  repository->read_position = 0;   // 初始化产品读取位置.
}

int main() {
  InitItemRepository(&item_repository);
  std::thread consumer(ConsumerTask);  // 创建消费之线程
  std::thread producer(ProducerTask);  // 创建生产者线程
  producer.join();
  consumer.join();
}