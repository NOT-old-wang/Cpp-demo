/*
Copyright [2019]
*/
#include <iostream>
#include "my_queue.h"

int main(int argc, char **argv) {
  MyQueue queue(3);
  if (queue.Empty()) {
    std::cout << "queue is empty. size is: " << queue.Size() << std::endl;
  }
  queue.Push(3);
  queue.Push(2);
  queue.Push(3);
  while (!queue.Empty()) {
    std::cout << queue.Back() << std::endl;
    queue.Pop();
  }
  return 0;
}
