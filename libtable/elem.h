#pragma once
#include "throws.h"

template <class T>
class TElem
{
protected:
  string key;
  T data;
public:
  TElem();
  TElem(string _key, T _data);
  TElem(TElem<T> &A);

  void SetKey(string _key);
  void SetData(T _data);
  string GetKey();
  T& GetData();

  TElem<T>& operator=(TElem<T> &A);
  bool operator==(TElem<T> &A);
  bool operator!=(TElem<T> &A);
};
template <class T>
TElem<T>::TElem()
{
  key = "";
  data = 0;
}
template <class T>
TElem<T>::TElem(string _key, T _data)
{
  key = _key;
  data = _data;
}
template <class T>
TElem<T>::TElem(TElem<T> &A)
{
  key = A.key;
  data = A.data;
}
template <class T>
TElem<T>& TElem<T>::operator=(TElem<T> &A)
{
  if (*this == A)
    throw TException("The same elements");
  key = A.key;
  data = A.data;
}
template <class T>
bool TElem<T>::operator==(TElem<T> &A)
{
  return key == A.key;
}
template <class T>
void TElem<T>::SetKey(string _key)
{
  key = _key;
}
template <class T>
void TElem<T>::SetData(T _data)
{
  data=_data;
}
template <class T>
string TElem<T>::GetKey()
{
  return key;
}
template <class T>
T& TElem<T>::GetData()
{
  return data;
}
template <class T>
bool TElem<T>::operator!=(TElem<T> &A)
{
  return !(*this == A);
}
