#pragma once
#include "elem.h"

template <class T>
class TTable
{
protected:
  TElem<T> not_find;
  TElem<T>* mas;
  int size, count;
public:
  TTable(int _size = 10);
  TTable(TTable<T> &A);

  void SetSize(int _size);
  int GetSize();
  int GetCount();

  void Put(string _key, T c);
  void Del(string _key);
  TElem<T>& Find(string _key);
  T& operator[](string _key);
};
template <class T>
TTable<T>::TTable(int _size)
{
  if (_size <= 0)
    throw TException("Error size");
  size = _size;
  count = 0;
  mas = new TElem<T>[size];
}
template <class T>
TTable<T>::TTable(TTable<T> &A)
{
  size = A.size;
  count = A.count;
  mas = new TElem<T>[size];
  for (int i = 0; i < count; i++)
    mas[i] = A.mas[i];
}
template <class T>
void TTable<T>::Put(string _key, T c)
{
  if (count == size)
    throw TException("Table is full");
  mas[count].SetKey(_key);
  mas[count].SetData(c);
  count++;
}
template <class T>
void TTable<T>::Del(string _key)
{
  if (count == 0)
    throw TException("Table is empty");
  TElem<T>& temp = Find(_key);
  if (tmp != not_find)
    tmp = not_find;
}
template <class T>
TElem<T>& TTable<T>::Find(string _key)
{
  for (int i = 0; i < count; i++)
    if (mas[i].GetKey() == _key)
      return mas[i];
    else return not_find;
}
template <class T>
T& TTable<T>::operator[](string _key)
{
  TElem<T>& temp = Find(_key);
  if (temp == not_find)
  {
    T a;
    cout << "Enter the data:\n";
      cin >> a;
    Put(_key, a);
    return mas[count - 1].GetData();
  }
  else return temp.GetData();;
}
template <class T>
void TTable<T>::SetSize(int _size)
{
  if (_size < count)
    throw TException("Error new size");
  TElem<T>* t = new TElem<T>[count];
  for (int i = 0; i < count; i++)
    t[i] = mas[i];
  delete[]mas;
  mas = new TElem<T>[_size];
  for (int i = 0; i < count; i++)
    mas[i] = t[i];
  size = _size;
  delete[]t;
}
template <class T>
int TTable<T>::GetSize()
{
  return size;
}
template <class T>
int TTable<T>::GetCount()
{
  return count;
}




