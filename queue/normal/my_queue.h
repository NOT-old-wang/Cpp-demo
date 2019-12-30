/*
Copyright [2019]
*/
#ifndef QUEUE_NORMAL_MY_QUEUE_H_
#define QUEUE_NORMAL_MY_QUEUE_H_

class MyQueue {
 public:
  explicit MyQueue(int capacity);
  virtual ~MyQueue();

  // 元素访问
  int Front();
  int Back();

  // 容量
  bool Empty() const { return 0 == size_ ? true : false; }
  int Size() const { return size_; }

  // 元素修改
  bool Push(const int& element);
  bool Pop();
  void Clear();

 private:
  bool Full() const { return capacity_ == size_ ? true : false; }

  int* buffer_;
  int size_;
  int capacity_;
  int head_;
  int tail_;
};

#endif  // QUEUE_NORMAL_MY_QUEUE_H_
