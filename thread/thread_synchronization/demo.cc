#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>

/*
实现外部调用线程1，线程1执行完成后自动调用线程2
*/
std::condition_variable cv;
std::mutex mutex;
bool sync = false;

void Thread_1() {
  std::unique_lock<std::mutex> lock(mutex);
  std::cout << " thread 1 exce... " << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  cv.notify_one();
  sync = true;
}

void Thread_2() {
  std::unique_lock<std::mutex> lock(mutex);
#if 0
  cv.wait(lock, [] { return sync; });
  std::cout << " thread 2 exce... " << std::endl;
  sync = false;
#endif

#if 0
  cv.wait(lock); // 不带谓词的话需要比 notify_one 提前运行到 wait
  std::cout << " thread 2 exce... " << std::endl;
  sync = false;
#endif

#if 0 
  // 超时后退出， 用的是 std::chrono::duration， 适合短时间，相对时间
  if (cv.wait_for(lock, std::chrono::milliseconds(1000), [] { return sync; })) {
    std::cout << " thread 2 exce... " << std::endl;
    sync = false;
  } else {
    std::cout << " thread 2 time out " << std::endl;
  }
#endif

#if 1
  // 超时后退出， 用的是 std::chrono::time_point， 绝对时间
  auto now = std::chrono::system_clock::now();
  if (cv.wait_until(lock, now + std::chrono::milliseconds(1000),
                  [] { return sync; })) {
    std::cout << " thread 2 exce... " << std::endl;
    sync = false;
  } else {
    std::cout << " thread 2 time out " << std::endl;
  }
#endif
}

int main(int argc, const char** argv) {
  std::thread t1(Thread_1);
  std::thread t2(Thread_2);
  t2.join();
  t1.join();
}