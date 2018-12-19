#pragma once

#include <iostream>

#include "stack.h"

template <class T>
class TNewStack : public TStack<T>
{
  /* int size;
   T* top;
   T* mas;*/
public:
  TNewStack(int _size = 0, T* _mas = 0);
  TNewStack(TNewStack<T> &A);
  int Free();
  void SetMas(int n, T* m);
  int GetSize();
  int GetTop();
};
template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
  if (_size < 0)
    throw - 1;
  else
  {
    if (_size == 0)
    {
      TStack<T>::top = -1;
      TStack<T>::size = 0;
      TStack<T>::mas = NULL;
    }
    else
    {
      TStack<T>::size = _size;
      TStack<T>::top = -1;
      TStack<T>::mas = _mas;
    }
  }
}
  template <class T>
  TNewStack<T>::TNewStack(TNewStack<T> &A)
  {
    TStack<T>::size = A.TStack<T>::size;
    TStack<T>::top = A.TStack<T>::top;
    TStack<T>::mas = A.TStack<T>::mas;
  }
  template <class T>
  int TNewStack<T>:: Free()
  {
    return TStack<T>::size - (TStack<T>::top+1);
  }
  template <class T>
  void TNewStack<T>::SetMas(int n, T* m)
  {
    TStack<T>::size = n;
    TStack<T>::mas = m;
  }
  template <class T>
  int TNewStack<T>::GetSize()
  {
    return TStack<T>::size;
  }
  template <class T>
  int TNewStack<T>::GetTop() {
    return TStack<T>::top;
  }



template <class T>
class TMStack
{
protected:
  int size;
  T* mas;
  int n;
  TNewStack<T>** h;
  int GetFreeMem(); //общее количество свободных ячеек в каждом стеке
  void Repack(int k);
public:
  TMStack(int _size, int _n); //конструктор инициализатор с номерм стека _n и его размером _size
  TMStack(TMStack<T> &A);
  void Put(int _n, const  T &A); //положить в стек номер _n значение A
  T Get(int _n); //взять из стека  номер _n элемент
  bool IsFull(int _n); //проверка на полноту
  bool IsEmpty(int _n); //проверка на пустоту
};
//.........................................
template <class T>
TMStack<T>::TMStack(int _size, int _n)
{
  if (_size < 0 || _n < 0)
    throw - 1;
  n = _n;
  size = _size;
  mas = new T[size];
  h = new TNewStack<T>*[n];
  int* p = new T[n]; //массив стеков
  p[0] = (size / n) + (size%n);
  for (int i = 1; i < n; i++)
    p[i] = size / n;
  h[0] = new TNewStack<T>(p[0], &mas[0]);
  for (int i = 1; i < n; i++)
    h[i] = new TNewStack<T>(p[i], &mas[p[0] + (i - 1) * p[i]]);
}
template <class T>
TMStack<T> ::TMStack(TMStack<T> &A)
{
  int sizeST = 0; //количество пришедших размеров массивов
  size = A.size;
  n = A.n;
  mas = new T[size];
  h = new TNewStack<T>*[n];
  for (int i = 0; i < n; i++) //копируем данные общего массива
    mas[i] = A.mas[i];
  int* p = new int[n];
  for (int i = 0; i < n; i++)
    p[i] = A.h[i]->GetSize();
  h[0] = new TNewStack<T>(*A.h[0]);
  for (int i = 1; i < n; i++)
  {
    h[i] = new TNewStack<T>(*A.h[i]);
    h[i]->SetMas(p[i], &mas[p[0] + sizeST]);
    sizeST += p[i - 1];
  }
}
//..............................................
template <class T>
int TMStack<T>::GetFreeMem()
{
  int count = 0;
  for (int i = 0; i < n; i++)
    count += h[i]->Free();
  return count;
}
template <class T>
void TMStack<T>::Repack(int k)
{
  int freeMem = GetFreeMem();
  if (freeMem == 0)
    throw - 1;
  int add_every = freeMem / n;
  int add_full = freeMem % n;
  int* newSize = new int[n]; //массив под новые размеры стеков
  T** old_start = new T*[n];
  T** new_start = new T*[n];
  for (int i = 0; i < n; i++)
    newSize[i] = add_every + h[i]->TNewStack<T>::GetTop();
  newSize[k] += add_full;
  new_start[0] = old_start[0] = mas;
  for (int i = 1; i < n; i++)
  {
    new_start[i] = new_start[i - 1] + newSize[i - 1];
    old_start[i] = old_start[i - 1] + h[i - 1]->TNewStack<T>::GetSize();
  }
  for (int i = 0; i < n; i++)
  {
    if (new_start[i] <= old_start[i])
      for (int j = 0; j < h[i]->TNewStack<T>::GetTop(); j++)
        new_start[i][j] = old_start[i][j];
    else
    {
      int s = i + 1;
      for (; s < n; s++)
        if (new_start[s] <= old_start[s])
          break;
      for (int j = s - 1; j >= i; j--)
        for (int r = h[i]->TNewStack<T>::GetTop() - 1; r >= 0; r--)
          new_start[j][r] = old_start[j][r];
      i = s - 1;
    }
  }
  for (int i = 0; i < n; i++)
    h[i]->TNewStack<T>::SetMas(newSize[i], new_start[i]);
  delete[] newSize;
  delete[] new_start;
  delete[] old_start;
}
//...............................................
template <class T>
void TMStack<T>::Put(int _n, const T &A)
{
  if (_n < 0 || _n >= size)
  {
    throw - 1;
  }
  if (IsFull(_n))
    Repack(_n);
  h[_n]->TStack<T>::Put(A);
}
//.......................................
template <class T>
T TMStack<T>::Get(int _n)
{
  if (_n < 0 && _n >= this->size)
    throw - 1;
  else
    if (IsEmpty(_n))
      throw - 1;
    else
      return (h[_n]->TStack<T>::Get());
}
//...............................................
template <class T>
bool TMStack<T>::IsFull(int _n)
{
  if (_n < 0 || _n >= this->size)
  {
    throw - 1;
  }
  return h[_n]->TStack<T>::IsFull();
}

template <class T>
bool TMStack<T>::IsEmpty(int _n)
{
  if (_n < 0 || _n >= this->size)
  {
    throw - 1;
  }
  return h[_n]->TStack<T>::IsEmpty();
}