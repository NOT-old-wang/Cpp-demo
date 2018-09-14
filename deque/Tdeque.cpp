#include <stdint.h>
#include <exception>

template<template T>
class Queue
{
  public:
    Queue(uint32_t max){
        capacity_ = max;
        size_ = 0;
        elements_ = new T[max];
        front = 0;
        rear = -1;
    }

    ~Queue(){
        delete [] elements_;
    }

    inline bool enqueue(const T &element) const {
        if (isFull())
            return false;
        size_++;
        rear_++;
        if(rear_ == capacity_){
            rear = 0;
        }
        elements_[rear_] = element;
        return true;
    }
    
  private:
    uint32_t capacity_;
    uint32_t size_;
    uint32_t front_;
    uint32_t rear_;
    T* elements_;
    class QueueEmpty:public std::exception{
        public:
            virtual const char* what() const throw(){
                return "Queue is empty."
            }
    } excp_empty;
    inline bool isFull() { return size_ == capacity_ ? true : false }
    inline bool isEmpty() { return 0 == size_ ? true : false }
};