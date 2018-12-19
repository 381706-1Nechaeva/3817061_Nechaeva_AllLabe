#pragma once
#include <iostream>
#include <math.h>
using namespace std;
template <class T>

class TStack
{
protected:
  int size;
  int top;
  T* mas;
public:
  TStack(int _size = 5);
  TStack(TStack<T> &A);
  ~TStack();

  void Put(const T &A);
  virtual  T Get();
  int GetSize(); //получить размер стека

  bool IsFull();
  bool IsEmpty();
};

//....................................
template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
    throw - 1;
  else
  {
    if (_size == 0)
    {
      top = -1;
      size = 0;
      mas = NULL;
    }
    else
    {
      size = _size;
      top = -1;
      mas = new T[size];
    }
  }
}
//......................................
template <class T>
TStack<T>::TStack(TStack <T> &A)
{
  top = A.top;
  size = A.size;
  mas = new T[size];
  for (int i = 0; i < A.size; i++)
    mas[i] = A.mas[i];
}
//......................................
template <class T>
TStack<T>::~TStack()
{
  delete[] mas;
}
//......................................
template <class T>
void TStack<T>::Put(const T &A)
{
  if (IsFull())
    throw -1;
  top++;
  mas[top] = A;
}
//......................................
template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw - 1;
  T res = mas[top];
  top--;
  return res;
}
//......................................
template <class T>
bool TStack<T>::IsEmpty()
{
  return top == -1;
}
//......................................
template <class T>
bool TStack<T>::IsFull()
{
  return top >= size-1;
}
template <class T>
int TStack<T>::GetSize()
{
  return size;
}
