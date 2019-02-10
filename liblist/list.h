#pragma once
#include <math.h>
#include "TElem.h"
#include "throws.h"

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
  void PutTek(const T &a, int tek); //положить в текущее
  T GetBegin(); //достать из начала с последующим удалением
  T GetEnd(); //достать из конца с последующим удалением
  T GetTek(int tek); //положить в текущее
  void Print(); //печать списка
  bool IsFull(); //проверка на полноту
  bool IsEmpty(); //проверка на пустоту
  int Count(); //получить количество звеньев в списке
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
  {
    TElem<T>* temp = new TElem<T>(a, 0);
    begin = temp;
  }
  else
  {
    TElem<T>* tmp = new TElem<T>(a, 0);
    TElem<T>* i;
    for (i = begin; i->GetNext() != 0; i = i->GetNext());
    i->SetNext(tmp);
  }
}
//................................................
template <class T>
void TList<T>::PutTek(const T &a, int tek)
{
  TElem<T>* i;
  int  j = 0;
  if (tek <= 1 || tek > this->Count())
    throw TException("Error location");
    i = begin;
    for (j = 1; j < tek - 1; i = i->GetNext())
      j++;
    TElem<T>* temp = new TElem<T>(a, i->GetNext());
    i->SetNext(temp);
}
//................................................
template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw TException("List is empty");
  else
  {
    TElem<T>* temp = begin;
    T res = begin->Get();
    begin = begin->GetNext();
    delete temp;
    return res;
  }
}
//................................................
template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw TException("List is empty");
  else
  {
    TElem<T>* i;
    i = begin;
    if (i->GetNext() == 0)
    {
      T res = i->Get();
      begin = i->GetNext();
      delete i;
      return res;
    }
    else
    {
      for (; i->GetNext()->GetNext() != 0; i = i->GetNext());
      T res = i->GetNext()->Get();
      delete i->GetNext();
      i->SetNext(0);
      return res;
    }
  }
}
//................................................
template <class T>
T TList<T>::GetTek(int tek)
{
  if (IsEmpty())
    throw TException("List is empty");
  TElem<T>* i;
  int j = 0;
  if (tek <= 1 || tek > this->Count())
    throw TException("Error location");
  i = begin;
  for (j = 1; j < tek - 1; i = i->GetNext())
    j++;
  T res = i->GetNext()->Get();
  TElem<T>* temp = i->GetNext();
  i->SetNext(temp->GetNext());
  delete temp;
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
//................................................
template <class T>
void TList<T>::Print()
{
  if (IsEmpty())
    throw TException("List is empty");
  else
  {
    TElem<T>* i;
    for (i = begin; i != 0; i = i->GetNext())
      cout << "  " << i->Get();
  }
}
//................................................
template <class T>
int TList<T>::Count()
{
  TElem<T>* i;
  int count = 0, j = 0;
  for (i = begin; i != 0; i = i->GetNext())
    count++;
  return count;
}
