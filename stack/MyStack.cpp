#include "Mystack.hpp"

Mystack::Mystack(int size)
{
    size_ = size;
    top_ = 0;
    m_pBuffer = new int[size_]; 
}

Mystack::~Mystack()
{
    delete [] m_pBuffer;
    m_pBuffer = NULL;
}

bool Mystack::push(int elem)
{
    if(stackFull())
    {
        return false;
    }  
    m_pBuffer[top_] = elem;
    top_++;
    return true;
}

bool Mystack::pop(int &elem)
{
    if(stackEmpty())
    {
        return false;
    }
    top_--;
    elem = m_pBuffer[top_];
    return true;
}

void Mystack::stackTraverse(bool formButton)
{
    if(formButton)
    {
       for(int i = top_; top_ > 0; i--)
       {
            std::cout << m_pBuffer[i] << ","
       }
    }
    else
    { 
       for(int i = 0; i < top_; i++)
       {
            std::cout << m_pBuffer[i] << ","
       }
    }
}