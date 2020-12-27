  
#pragma once

#include <iostream>

const int MaxSize = 100;

template <class St>
class CMyStack
{
  St *pMem;
  int size;
  int top;
  CMyStack(const CMyStack &stack) {}
  CMyStack& operator=(const CMyStack &stack) {}
  public:
    
  CMyStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > Maxize))
        throw std::logic_error("Invalid stack size");
    pMem = new St[size];
  }
    
  bool IsEmpty()
  {
	  return top == -1;
  }
    
  bool IsFull()
  {
	  return top == (size - 1);
  }
    
  void push(St val)
  {
	  if (IsFull())
		  throw std::logic_error("Too much elements in stack");
	  pMem[++top] = val;
  }
    
  T pop()
  {
	  if (IsEmpty())
		  throw std::logic_error("No elements in stack(empty)");
	  return pMem[top--];
  }
    
  ~ CMyStack()
  {
    delete [] pMem;
  }
    
};
