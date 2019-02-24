#pragma once
#include "list.h"

template <class T>
class TStackList : public TList<T>
{
public:
  TStackList(); //конструктор по умолчанию
  TStackList(TStackList <T> &A); //конструктор копирования
  void PrintTSL(); //печать стека
  int GetSize(); //получить размер стека
  void Put(const T &a); //положить в стек
  T Get(); //забрать из стека
  bool IsEmpty(); //проверка на пустоту
  bool IsFull(); //проверка на полноту
};

//.........................................................
template <class T>
TStackList<T>::TStackList() : TList<T>()
{
}
//.........................................................
template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
}
//.........................................................
template <class T>
void TStackList<T>::Put(const T &a)
{
  TList<T>::PutBegin(a);
}
//.........................................................
template <class T>
T TStackList<T>::Get()
{
  return TList<T>::GetBegin();
}
//.........................................................
template <class T>
int TStackList<T>::GetSize()
{
  return TList<T>::Count();
}
//.........................................................
template <class T>
bool TStackList<T>::IsEmpty()
{
  return TList<T>::IsEmpty();
}
//.........................................................
template <class T>
bool TStackList<T>::IsFull()
{
  return TList<T>::IsFull();
}
//.........................................................
template <class T>
void TStackList<T>::PrintTSL()
{
  return TList<T>::Print();
}