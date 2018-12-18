#pragma once
#include <iostream>
#include <math.h>
#include "stack.h"

using namespace std;
template <class T>

class TQueue :public TStack<T>
{
protected:
  int count;
  int start;
public:
  TQueue(int _size=5);
  void Put(const T &A);
  T Get();
  bool IsEmpty() { return count == 0; }
};
 
//....................................
template <class T>
TQueue<T>::TQueue(int _size) :TStack<T>(_size)
{
  count = 0;
  start = 0;
}
//....................................
template <class T>
void TQueue<T>::Put(const T &A)
{
  TStack<T>::Put(A);
  count++;
}
//....................................
template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw - 1;
  T res = this->mas[start];
  this->top = ++start%this->size;
  count--;
  return res;
}

  

