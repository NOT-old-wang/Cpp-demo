/*
Copyright [2019]
*/
#include "my_queue.h"

MyQueue::MyQueue(int capacity) : capacity_(capacity), head_(0), tail_(-1) {
  buffer_ = new int[capacity_];
}

MyQueue::~MyQueue() {
  delete[] buffer_;
  buffer_ = nullptr;
}

int MyQueue::Front() {
  if (size_ > 0) {
    return buffer_[head_];
  }
  return 0;
}

int MyQueue::Back() {
  if (size_ >0) {
    return buffer_[tail_];
  }
}

bool MyQueue::Push(const int& element) {
  if (!Full()) {
    tail_++;
    buffer_[tail_] = element;
    size_++;
    return true;
  }
  return false;
}

bool MyQueue::Pop() {
  if (!Empty()) {
    buffer_[head_] = 0;
    head_++;
    size_--;
    return true;
  }
  return false;
}

// void MyQueue::Clear() {
//   head_ = 0;
//   tail_ = 0;
//   size_ = 0;
//   buffer_ = nullptr;
// }
