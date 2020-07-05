#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <string>
#include <thread>

std::mutex mutex;
std::condition_variable cv;
bool ready = false;
bool processed = false;
std::string data;

void work_thread() {
  std::unique_lock<std::mutex> lock(mutex);
  cv.wait(lock, [] { return ready; });
  data += " work process ... -->";
  processed = true;
  // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
  lock.unlock();
  cv.notify_one();
}

int main(int argc, const char** argv) {
  std::thread worker(work_thread);

  // 准备数据
  {
    std::unique_lock<std::mutex> lock(mutex);
    data = "demo data ready -->";
    ready = true;
  }
  cv.notify_one();

  // 等待 worker 处理完
  {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [] { return processed; });
    data += " finished!";
  }
  std::cout << "back main, data is: " << data << std::endl;
  worker.join();
  return 0;
}