#include <iostream>

using namespace std;

class queue
{
  public:
    queue(int queueCapacity);
    virtual ~queue();
    void clearQueue();       
    bool queueEmpty() const { return 0 == len_ ？true : false; }
    bool queueFull() const { return queueCapacity_ == len_ ? true : false;}
    int queueLength() const { return len_;};
    bool enQueue(int element);
    bool deQueue(int &element);
    void queueTraverse();
  private:
    int *p_;
    int len_;
    int queueCapacity_;
    int head_;
    int tail_;
}

queue::queue(int queueCapacity) : queueCapacity_(queueCapacity)
{
    //queueCapacity_ = queueCapacity;
    clearQueue();
    p_ = new int[queueCapacity_];
}

queue::~queue()
{
    delete []p_;
    p_ = NULL;
}

void queue::clearQueue()
{
    head_ = 0, tail_ = 0, len_ = 0;
}

bool queue::(int element)
{
    if(!queueFull())
    {
        p_[tail_] = element;
        tail_++;
        len_++;
        tail_ = tail_ % queueCapacity_; 
        return true;
    } return false;
}

bool queue::deQueue(int &element)
{
    if(!queueEmpty())
    {
        element = p_[head_];
        head_++;
        head_ = head_ % queueCapacity_;
        len_--;
        return true;
    }
return false;
}

void queue::queueTraverse()
{
    for(int i = head_, i < len_ + head_, i++ )
    {
        cout << p_[i % queueCapacity_] << endl;

    }
}

int main(int argc, char ** argv)
{    
    queue *p = new queue(4);
    p->enQueue(10);
    p->enQueue(12);
    p->enQueue(10);
    p->enQueue(12);
   delete p;
}
