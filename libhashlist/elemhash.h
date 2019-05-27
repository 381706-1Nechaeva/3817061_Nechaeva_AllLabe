#pragma once
#pragma once
#include "throws.h"

template <class T>
class THashElem
{
protected:
  string key;
  T data;
  THashElem<T> *next;
public:
  THashElem();
  THashElem(string _key, T _data, THashElem<T> *_next);
  THashElem(THashElem<T> &A);

  void SetKey(string _key);
  void SetData(T _data);
  void SetNext(THashElem<T> *_next);
  string GetKey();
  T& GetData();
  THashElem<T>* GetNext();

  THashElem<T>& operator=(THashElem<T> &A);
  bool operator==(THashElem<T> &A);
  bool operator!=(THashElem<T> &A);
};
template <class T>
THashElem<T>::THashElem()
{
  key = "";
  data = 0;
  next = NULL;
}
template <class T>
THashElem<T>::THashElem(string _key, T _data, THashElem<T> *_next)
{
  key = _key;
  data = _data;
  next = _next;
}
template <class T>
THashElem<T>::THashElem(THashElem<T> &A)
{
  key = A.key;
  data = A.data;
  next = A.next;
}
template <class T>
THashElem<T>& THashElem<T>::operator=(THashElem<T> &A)
{
  if (*this == A)
    throw TException("The same elements");
  key = A.key;
  data = A.data;
  next = A.next;
}
template <class T>
bool THashElem<T>::operator==(THashElem<T> &A)
{
  return key == A.key;
}
template <class T>
void THashElem<T>::SetKey(string _key)
{
  key = _key;
}
template <class T>
void THashElem<T>::SetData(T _data)
{
  data = _data;
}
template <class T>
void THashElem<T>::SetNext(THashElem<T> *_next)
{
  next = _next;
}
template <class T>
string THashElem<T>::GetKey()
{
  return key;
}
template <class T>
T& THashElem<T>::GetData()
{
  return data;
}
template <class T>
THashElem<T>* THashElem<T>::GetNext()
{
  return next;
}
template <class T>
bool THashElem<T>::operator!=(THashElem<T> &A)
{
  return !(*this == A);
}

