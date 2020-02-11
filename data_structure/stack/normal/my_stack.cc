/*
Copyright [2019]
*/
#include "my_stack.h"

MyStack::MyStack(int capacity) : capacity_(capacity), size_(0), top_(-1) {
  buffer = new int[capacity_];
}

MyStack::~MyStack() {
  delete[] buffer;
  buffer = nullptr;
}

bool MyStack::Push(const int& elem) {
  if (Full()) {
    return false;
  }
  top_++;
  buffer[top_] = elem;
  size_++;
  return true;
}

bool MyStack::Pop() {
  if (Empty()) {
    return false;
  }
  top_--;
  size_--;
  return true;
}
