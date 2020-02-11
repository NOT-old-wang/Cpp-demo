/*
Copyright [2019]
*/
#ifndef STACK_NORMAL_MY_STACK_H_
#define STACK_NORMAL_MY_STACK_H_

class MyStack {
 public:
  explicit MyStack(int capacity);
  ~MyStack();

  int Top() { return buffer[top_]; }

  bool Empty() { return 0 == size_ ? true : false; }
  int Size() { return size_; }

  bool Push(const int &elem);
  bool Pop();
  void Clear() { top_ = 0; }

 private:
  bool Full() { return capacity_ == size_ ? true : false; }

  int top_;
  int size_;
  int capacity_;
  int *buffer;
};

#endif  // STACK_NORMAL_MY_STACK_H_
