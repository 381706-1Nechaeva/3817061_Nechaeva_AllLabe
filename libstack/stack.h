#pragma once
#include <math.h>
#include "throws.h"

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
  void Print(); //вывод стека
  int GetTop();
  void Repack();
  bool IsFull();
  bool IsEmpty();
};

//....................................
template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
    throw TException("Error size");
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
    Repack();
  top++;
  mas[top] = A;
}
//......................................
template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw TException("Stack is empty");
  return mas[top--];
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
  return top >= size - 1;
}
template <class T>
int TStack<T>::GetSize()
{
  return size;
}
template <class T>
void TStack<T>::Print()
{
  for (int i = top; i >= 0; i--)
    cout << "  {" << mas[i] << "}\n";
}
template <class T>
int TStack<T>::GetTop()
{
  return top;
}
template <class T>
void TStack<T>::Repack()
{
  if (IsFull())
  {
    T* temp = new T[size];
    int _size = size * 2;
    for (int i = 0; i < size; i++)
      temp[i] = mas[i];
    delete[]mas;
    mas = new T[_size];
    for (int i = 0; i < size; i++)
      mas[i] = temp[i];
    size = _size;
    delete[]temp;
  }
}
