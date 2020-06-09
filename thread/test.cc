#include <chrono>
#include <iostream>
#include <thread>

// std::mutex 独占的互斥量，不能递归使用 
// std::timed_mutex 带超时的独占的互斥量，不能递归使用 
// std::recursive_mutex 递归互斥量，不带超时功能 
// std::recursive_timed_mutex 带超时的递归互斥量

int k = 0;

void fun(void) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  for (int i = 0; i < 10; i++) {
    k++;
    std::cout << "hello thread " << k << std::endl;
  }
}




int main(int argc, const char** argv) {
  std::thread t1(fun);
  std::cout << "ID: " << t1.get_id() << std::endl;
  std::cout << "CPU: " << t1.hardware_concurrency() << std::endl;
  t1.join();

  std::cout << k << std::endl;
  return 0;
}