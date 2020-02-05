#include <functional>
#include <iostream>
#include "thread_test.h"

int main(int argc, const char** argv) {
  FuncOrderManager func_order_manager;
  std::function<void(std::function<void()>)> first = std::bind(
      &FuncOrderManager::First, &func_order_manager, std::placeholders::_1);
  std::function<void(std::function<void()>)> second = std::bind(
      &FuncOrderManager::Second, &func_order_manager, std::placeholders::_1);
  std::function<void(std::function<void()>)> third = std::bind(
      &FuncOrderManager::Third, &func_order_manager, std::placeholders::_1);

  std::thread thread_a(first, DoingA);
  std::thread thread_b(second, DoingB);
  std::thread thread_c(third, DoingC);

  thread_c.join();
  thread_b.join();
  thread_a.join();
  return 0;
}
