#pragma once

#include <iostream>
using namespace std;

const int Max = 100;

template <class T>
class TStack
{
    int size;
    int head;
    T* pMem;
    TStack(const TStack& st) {}
    TStack& operator=(const TStack& st) {}

public:

    TStack(int _size)
    {
        size = _size;
        head = -1;
        if ((size < 1) || (size > Max)) throw logic_error("Invalid stack size");
        pMem = new T[size];
    }

    ~TStack()
    {
        delete[] pMem;
    }

    bool empty() { return head == -1; }

    bool full() { return head == (size - 1); }

    void push(T val)
    {
        if (full()) throw logic_error("The stack is full");
        pMem[++head] = val;
    }

    T pop()
    {
        if (empty()) throw logic_error("The stack is empty");
        return pMem[head--];
    }
};
