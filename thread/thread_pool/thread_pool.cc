#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

class ThreadPool {
 public:
  explicit ThreadPool(size_t thread_size);
  template <typename F, typename... Args>
  auto EnQueue(F&& f, Args&&... args)
      -> std::future<typename std::result_of<F(Args...)>::type>;
  ~ThreadPool();

 private:
  // need to keep track of threads so we can join them
  std::vector<std::thread> workers_;
  // the task queue
  std::queue<std::function<void()>> tasks_;

  std::mutex queue_mutex_;
  std::condition_variable condition_;
  bool stop_;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t thread_size) : stop_(false) {
  auto thread_handler = [this] {
    for (;;) {
      std::function<void()> task;

      {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        condition_.wait(lock, [this] { return stop_ || !tasks_.empty(); });
        if (stop_ && tasks_.empty()) return;
        task = std::move(tasks_.front());
        tasks_.pop();
      }

      task();
    }
  };

  for (size_t i = 0; i < thread_size; ++i) {
    workers_.emplace_back(thread_handler);
  }
}

// add new work item to the pool
template <class F, class... Args>
auto ThreadPool::EnQueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type> {
  using return_type = typename std::result_of<F(Args...)>::type;

  auto task = std::make_shared<std::packaged_task<return_type()>>(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...));

  std::future<return_type> res = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);

    // don't allow enqueueing after stopping the pool
    if (stop_) throw std::runtime_error("enqueue on stopped ThreadPool");

    tasks_.emplace([task]() { (*task)(); });
  }
  condition_.notify_one();
  return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop_ = true;
  }

  condition_.notify_all();

  for (std::thread& worker : workers_) {
    worker.join();
  }
}

void Task1(int time) {
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "task 1" << std::endl;
  }
}

std::string Task2(std::string s) {
  std::cout << "task 2" << std::endl;
  return s;
}

void Task3() {
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  std::cout << "task 3" << std::endl;
}

int main(int argc, const char** argv) {
  ThreadPool thread_pool(2);
  thread_pool.EnQueue(Task1, 1000);
  auto s = thread_pool.EnQueue(Task2, "task 2 finished");
  std::cout << s.get() << std::endl;
  thread_pool.EnQueue(Yask3);
  // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  return 0;
}