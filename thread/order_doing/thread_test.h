/*
Copyright [2019]
*/
#ifndef THREAD_STL_TEST_THREAD_TEST_H_
#define THREAD_STL_TEST_THREAD_TEST_H_
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

static void DoingA() {
  std::cout << "doing A" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

static void DoingB() {
  std::cout << "doing B" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

static void DoingC() {
  std::cout << "doing C" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

/*
函数顺序管理类，让指定的函数在多线程下按顺序执行
*/
class FuncOrderManager {
 public:
  FuncOrderManager() : count_(1) {}
  void First(std::function<void()> fun) {
    std::unique_lock<std::mutex> lock(mutex_);
    cv3_.wait(lock, [this]() { return count_ == 1; });
    std::cout << "first..." << std::endl;
    fun();
    count_ = 2;
    cv1_.notify_one();
  }
  void Second(std::function<void()> fun) {
    std::unique_lock<std::mutex> lock(mutex_);
    cv1_.wait(lock, [this]() { return count_ == 2; });
    std::cout << "second..." << std::endl;
    fun();
    count_ = 3;
    cv2_.notify_one();
  }
  void Third(std::function<void()> fun) {
    std::unique_lock<std::mutex> lock(mutex_);
    cv2_.wait(lock, [this]() { return count_ == 3; });
    std::cout << "third..." << std::endl;
    fun();
    count_ = 1;
    cv3_.notify_one();
  }

 private:
  std::mutex mutex_;
  std::condition_variable cv1_;
  std::condition_variable cv2_;
  std::condition_variable cv3_;
  int count_;
};

#endif  // THREAD_STL_TEST_THREAD_TEST_H_
