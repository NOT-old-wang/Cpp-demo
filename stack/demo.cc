/*
Copyright [2019]
*/
#include <iostream>
#include "my_stack.h"

#define USE_NORMAL
// #define USE_TEMPLATE

int main(int argc, const char** argv) {
#ifdef USE_NORMAL
  MyStack stack(3);
  if (stack.Empty()) {
    std::cout << "stack is empty. size is: " << stack.Size() << std::endl;
  }
  stack.Push(3);
  stack.Push(2);
  stack.Push(1);
  std::cout << "stack size is: " << stack.Size() << std::endl;
  while (!stack.Empty()) {
    std::cout << stack.Top() << ", ";
    stack.Pop();
  }
  std::cout << std::endl;
#endif

  return 0;
}
