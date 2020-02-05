/*
Copyright [2019]
*/
#ifndef QUEUE_TEMPLATE_MY_QUEUE_H_
#define QUEUE_TEMPLATE_MY_QUEUE_H_

#include <stdint.h>
#include <exception>

template <typename T>
class MyQueue {
 public:
  explicit MyQueue(uint32_t max) {
    capacity_ = max;
    size_ = 0;
    elements_ = new T[max];
    front_ = 0;
    rear_ = -1;
  }

  ~MyQueue() { delete[] elements_; }

  bool Push(const T& element) const;

 private:
  uint32_t capacity_;
  uint32_t size_;
  uint32_t front_;
  uint32_t rear_;
  T* elements_;
  class QueueEmpty : public std::exception {
   public:
    virtual const char* what() const throw() { return "Queue is empty."; }
  } excp_empty;
  inline bool isFull() { return size_ == capacity_ ? true : false; }
  inline bool isEmpty() { return 0 == size_ ? true : false; }
};

#endif  // QUEUE_TEMPLATE_MY_QUEUE_H_
