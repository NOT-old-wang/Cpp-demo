/*
Copyright [2019]
*/
#ifndef STACK_NORMAL_MY_STACK_H_
#define STACK_NORMAL_MY_STACK_H_

class MyStack {
 public:
  explicit MyStack(int size);
  ~MyStack();

  bool Empty() { return 0 == top_ ? true : false; }
  int Size() { return top_; }

  bool Push(const int &elem);
  bool Pop();
  void Clear() { top_ = 0; }

 private:
  bool Full() { return size_ == top_ ? true : false; }

  int top_;
  int size_;
  int *buffer;
};

#endif  // STACK_NORMAL_MY_STACK_H_
