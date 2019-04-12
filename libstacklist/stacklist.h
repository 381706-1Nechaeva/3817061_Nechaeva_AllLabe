#pragma once
#include "list.h"

template <class T>
class TStackList : public TList<T>
{
public:
  TStackList(); //����������� �� ���������
  TStackList(TStackList <T> &A); //����������� �����������
  void PrintTSL(); //������ �����
  int GetSize(); //�������� ������ �����
  void Put(const T &a); //�������� � ����
  T Get(); //������� �� �����
  bool IsEmpty(); //�������� �� �������
  bool IsFull(); //�������� �� �������
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