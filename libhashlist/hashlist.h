#pragma once
#include "elemhash.h"

template <class T>
class THashTable
{
protected:
  THashElem<T> not_find;
  THashElem<T>** mas;
  int size;
  int Hash(string _key);
public:
  THashTable(int _size = 10);
  THashTable(THashTable<T> &A);

  void SetSize(int _size);
  int GetSize();

  void Put(string _key, T c);
  void Del(string _key);
  T Find(string _key);
  void Print();
};
template <class T>
THashTable<T>::THashTable(int _size)
{
  if (_size <= 0)
    throw TException("Error size");
  size = _size;
  mas = new THashElem<T>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = 0;
}
template <class T>
THashTable<T>::THashTable(THashTable<T> &A)
{
  size = A.size;
  mas = new THashElem<T>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = A.mas[i];
}
template <class T>
void THashTable<T>::Put(string _key, T c)
{
  int h = Hash(_key);
  if (mas[h] == 0)
    mas[h] = new THashElem<T>(_key, c,0);
  else
  {
    THashElem<T> *n = new THashElem<T>(_key, c,0);
    n->SetNext(mas[h]);
    mas[h] = n;
  }
}
template <class T>
int THashTable<T>::Hash(string _key)
{
  int c = _key[0];
  int h;
  h = c % size;
  return h;
}
template <class T>
void THashTable<T>::Del(string _key)
{
  int h = Hash(_key);
  THashElem<T> *j = mas[h];
  THashElem<T> *p = 0;
  if(mas[h]==0)
    throw TException("Table is empty");
  if (mas[h]->GetNext() == 0)
    mas[h] = 0;
  else
  {
    while (j->GetKey() != _key && j->GetNext() != 0)
    {
      p = j;
      j = j->GetNext();
    }
      if (j->GetKey() == _key)
      {
        if (p != 0)
          p->SetNext(j->GetNext());
        else
          mas[h] = j->GetNext();
      }
    }
}
template <class T>
T THashTable<T>::Find(string _key)
{
  int h = Hash(_key);
  if(mas[h]==0)
    return not_find.GetData();
  if (mas[h]->GetKey() == _key)
    return mas[h]->GetData();
  else if (mas[h]->GetNext() != 0)
  {
    THashElem<T> *tmp = mas[h];
    while (tmp != 0)
    {
      tmp = tmp->GetNext();
      if (tmp->GetKey() == _key)
        return tmp->GetData();
    }
  }
  return not_find.GetData();
}
template <class T>
void THashTable<T>::SetSize(int _size)
{
  if (_size <= size)
    throw TException("Error new size");
  THashElem<T> **tmp;
  tmp = new THashElem<T>*[_size];
  for (int i = 0; i < size; i++)
    tmp[i] = mas[i];
  delete mas;
  int old = size;
  size = _size;
  mas= new THashElem<T>*[size];
  for (int i = 0; i < old; i++)
    mas[i] = tmp[i];
  for (int i = old; i < size; i++)
    mas[i] = 0;
  delete tmp;
}
template <class T>
int THashTable<T>::GetSize()
{
  return size;
}
template <class T>
void THashTable<T>::Print()
{
  for (int i = 0; i < size; i++)
    if (mas[i] != 0)
    {
      if (mas[i]->GetNext() == 0)
        cout << mas[i]->GetKey() << "---->" << mas[i]->GetData() << endl;
      else
        while (mas[i] != 0)
        {
          cout << mas[i]->GetKey() << "---->" << mas[i]->GetData() << endl;
          mas[i] = mas[i]->GetNext();
        }
    }
}



