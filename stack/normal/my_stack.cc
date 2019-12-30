/*
Copyright [2019]
*/
#include "my_stack.h"

MyStack::MyStack(int size) {
  size_ = size;
  top_ = 0;
  buffer = new int[size_];
}

MyStack::~MyStack() {
  delete[] buffer;
  buffer = nullptr;
}

bool MyStack::Push(const int& elem) {
  if (Full()) {
    return false;
  }
  buffer[top_] = elem;
  top_++;
  return true;
}

bool MyStack::Pop() {
  if (Empty()) {
    return false;
  }
  top_--;
  return true;
}
