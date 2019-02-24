#pragma once
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
  TQueue(TQueue<T> &A);
  void Put(const T &A);
  T Get();
  void Print();

  bool IsEmpty() { return count == 0; }
  bool IsFull() { return count == TStack<T>::size; }
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
TQueue<T>::TQueue(TQueue<T> &A) :TStack<T>(A)
{
  count = A.count;
  start = A.start;
}
//....................................
template <class T>
void TQueue<T>::Put(const T &A)
{
  if (IsFull())
    throw TException("Queue is full");
  TStack<T>::Put(A);
  if (TStack<T>::top >= TStack<T>::size - 1)
    TStack<T>::top = -1;
  count++;
}
//....................................
template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw TException("Queue is empty");
  T res = this->mas[start];
  start++;
  if (start >= TStack<T>::size)
    start = 0;
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
    if (TStack<T>::top < start)
    {
      for (int i = start; i < TStack<T>::size; i++)
        cout << TStack<T>::mas[i] << "\t";
      for (int i = 0; i < TStack<T>::top + 1; i++)
        cout << TStack<T>::mas[i] << "\t";
    }
    else
      for (int i = start; i < TStack<T>::top + 1; i++)
        cout << TStack<T>::mas[i] << "\t";
    cout << "\n";
  }
}