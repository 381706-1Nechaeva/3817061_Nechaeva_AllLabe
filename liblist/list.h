#pragma once
#include <iostream>
#include <math.h>
#include "TElem.h"

using namespace std;
template <class T>
class TList
{
protected:
  TElem<T>* begin; //указатель на начало списка
public:
  TList(); //конструктор по умолчанию
  TList(TList<T> &A); //конструктор копирования
  void PutBegin(const T &a); //положить в начало
  void PutEnd(const T &a); //положить в конец
  T GetBegin(); //достать из начала с последующим удалением
  T GetEnd(); //достать из конца с последующим удалением
  bool IsFull(); //проверка на полноту
  bool IsEmpty(); //проверка на пустоту
};
//................................................
template <class T>
TList<T>::TList()
{
  begin = 0;
}
//................................................
template <class T>
TList<T>::TList(TList<T> &A)
{
  begin = 0;
  for (TElem<T>* i = A.begin; i != 0; i = i->GetNext())
  {
    if (i == A.begin)
      this->PutBegin(i->Get());
    else
      this->PutEnd(i->Get());
  }
}
//................................................
template <class T>
void TList<T>::PutBegin(const T &a)
{
  TElem<T>* temp = new TElem<T>(a, begin);
  begin = temp;
}
//................................................
template <class T>
void TList<T>::PutEnd(const T &a)
{
  if (IsEmpty())
    throw - 1;
  TElem<T>* tmp = new TElem<T>(a, 0);
  TElem<T>* i;
  for (i = begin; i->GetNext() != 0; i = i->GetNext());
  i->SetNext(tmp);
}
//................................................
template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw - 1;
  T res = begin->Get();
  begin = begin->GetNext();
  return res;
}
//................................................
template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw - 1;
  TElem<T>* i;
  for (i = begin; i->GetNext()->GetNext() != 0; i = i->GetNext());
  T res = i->GetNext()->Get();
  delete i->GetNext()->GetNext();
  i->SetNext(0);
  return res;
}
//................................................
template <class T>
bool TList<T>::IsFull()
{
  TElem<T>* tmp = new TElem<T>;
  if (tmp == 0)
    return true;
  else
    return false;
}
//................................................
template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return true;
  else
    return false;
}
