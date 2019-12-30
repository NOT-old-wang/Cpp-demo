/*
Copyright [2019]
*/
#include "my_queue.h"

MyQueue::MyQueue(int capacity) : capacity_(capacity), head_(0), tail_(0) {
  buffer_ = new int[capacity_];
}

MyQueue::~MyQueue() {
  delete[] buffer_;
  buffer_ = nullptr;
}

int MyQueue::Front() {
  if (buffer_ != nullptr) {
    return buffer_[head_];
  }
  return 0;
}

bool MyQueue::Push(const int& element) {
  if (!Full()) {
    buffer_[tail_] = element;
    tail_++;
    size_++;
    tail_ = tail_ % capacity_;
    return true;
  }
  return false;
}

bool MyQueue::Pop() {
  if (!Empty()) {
    head_++;
    head_ = head_ % capacity_;
    size_--;
    return true;
  }
  return false;
}

void MyQueue::Clear() {
  head_ = 0;
  tail_ = 0;
  size_ = 0;
  buffer_ = nullptr;
}
