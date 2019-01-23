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
  TQueue(int _size = 5);
  void Put(const T &A);
  T Get();
  void Print();

  bool IsEmpty() { return count == 0; }
  bool IsFull() { return count == size; }
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
  if (IsFull())
    throw - 1;
  TStack<T>::Put(A);
  if (top >= size - 1)
    top = -1;
  count++;
}
//....................................
template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw - 1;
  T res = this->mas[start];
  start++;
 // this->top = ++start%this->size;
  if (start >= size)
    start = 0;
  //if (top >= size - 1)
  //  top = -1;
  count--;
  return res;
}
template<class T>
void TQueue<T>::Print()
{
  if (count == 0)
    cout << "Очередь пустая\n";
  else
  {
    if (top < start)
    {
      for (int i = start; i < size; i++)
        cout << mas[i] << "\t";
      for (int i = 0; i < top + 1; i++)
        cout << mas[i] << "\t";
    }
    else
      for (int i = start; i < top + 1; i++)
        cout << mas[i] << "\t";
    cout << "\n";
  }
}