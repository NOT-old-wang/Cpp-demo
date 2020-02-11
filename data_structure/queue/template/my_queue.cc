/*
Copyright [2019]
*/
#include "my_queue.h"

template <typename T>
bool MyQueue::Push(const T& element) {
  if (isFull()) return false;
  size_++;
  rear_++;
  if (rear_ == capacity_) {
    rear_ = 0;
  }
  elements_[rear_] = element;
  return true;
}
