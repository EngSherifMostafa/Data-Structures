#ifndef QUEUElINKED_H
#define QUEUElINKED_H
#include <iostream>
#include "StackLinked.cpp"
using namespace std;

template <class T>
class QueueLinked
{
public:
   bool isEmpty() const;
   bool isFull() const;
   void getFront(T&) const;
   void enQueue(T);
   void deQueue(T&);
   int queueLength() const;
   void traverse() const;

private:
    StackLinked<T> s1,s2;
};
#endif
