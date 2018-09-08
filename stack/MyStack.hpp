#pragma once

class MyStack
{
  public:
    MyStack(int size);
    ~MyStack();
    bool stackEmpty() { return 0 == top_ ? true : false; }
    bool stackFull()  { return size_ == top_ ? true : false; }
    void clearStack() { top_ = 0; }
    int stackLength() { return top_; }
    void push(int elem);
    void pop(int &elem);
    void stackTraverse(bool formButton);

  private:
    int top_;
    int size_;
    char *m_pBuffer;
};