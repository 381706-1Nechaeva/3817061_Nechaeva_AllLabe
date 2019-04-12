#pragma once
#include <iostream>

using namespace std;
template <class T>
class TElem {
private:
  T elem; //��������
  TElem<T>* next;//��������� �� ���� �������
public:
  TElem(T _elem = 0, TElem<T>* _next = 0); //����������� �������������
  T Get(); //�������� �������� ��������
  TElem* GetNext(); //�������� ��������� �� ��������� �������
  void Set(T _elem); //���������� ��������
  void SetNext(TElem<T>* _next); //���������� ��������� �� ��������� �������
};
//................................................
template <class T>
TElem<T>::TElem(T _elem, TElem<T>* _next)
{
  elem = _elem;
  next = _next;
}
//................................................
template <class T>
T TElem<T>::Get()
{
  return elem;
}
//................................................
template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}
//................................................
template <class T>
void TElem<T>::Set(T _elem)
{
  elem = _elem;
}
//................................................
template <class T>
void TElem<T>::SetNext(TElem<T>* _next)
{
  next=_next;
}

