#pragma once
#include "sortelem.h"

template <class T>
class TSortTable
{
protected:
  TElem<T> not_find;
  TElem<T> *mas;
  int size;
  int count; //кол-во исп элементов таблицы
public:
  TSortTable(string* _key, T* _data, int _size = 3);
  TSortTable(int _size = 10);
  TSortTable(TSortTable<T> &A);
  int Put(string _key, T _data);
  void Del(string _key);
  TElem<T>& Search(string k);
  void Resize(int _size);
  T& operator[](string k);
  int GetCount();
  int GetSize();
};
//.........................................................
template <class T>
TSortTable<T>::TSortTable(string* _key, T* _data, int _size) //два массива и размер
{
  mas = new TElem<T>[_size];
  size = _size;
  count = 0;
  for (int i = 0; i < size; i++)
    Put(TElem<T>(_key[i], _data[i]));
}
//.........................................................
template <class T>
TSortTable<T>::TSortTable(int _size)
{
  if (_size <= 0)
    throw TException("Error size");
  size = _size;
  count = 0;
  mas = new TElem<T>[size];
}
//.........................................................
template <class T>
TSortTable<T>::TSortTable(TSortTable<T> &A)
{
  size = A.size;
  count = A.count;
  mas = new TElem<T>[size];
  for (int i = 0; i < count; i++)
    mas[i] = A.mas[i];
}
//.........................................................
template <class T>
int TSortTable<T>::Put(string k, T _data) // int чтобы узнать индекс элемента, который добавили
{
  if (size <= count)
    Resize(count * 2);
  int left = 0, right = count, cur = count / 2;;
  while (left <= right)
    {
    cur = (left + right) / 2;
    if (left == right)
      break;
      if (mas[cur].GetKey() > k)
      {
        right = cur;
      }
      else if (mas[cur].GetKey() < k)
      {
        left = cur+1;
      }
      else
        throw TException("The same element");
    }
    for (int i = count - 1; i >= cur; i--)
      mas[i + 1] = mas[i];
    TElem<T> temp(k, _data);
    mas[cur] = temp;
    count++;
    return cur;
  }
//.........................................................
template <class T>
void TSortTable<T>::Del(string k)
{
  if (count == 0)
    throw TException("Table is empty");
  int left = 0, right = count, cur = count / 2;
  while (left <= right)
    {
      cur = (left + right) / 2;
      if (mas[cur].GetKey() > k)
      {
        right = cur-1;
      }
      else if (mas[cur].GetKey() < k)
      {
        left = cur+1;
      }
      else
        for (int i = cur; i < count; i++)
          mas[i] = mas[i + 1];
    }
  count--;
  }
//.........................................................
template <class T>
TElem<T>& TSortTable<T>::Search(string k)
{
  int left = 0;
  int right = count;
  int cur = count / 2;
  while (left <= right)
  {
    cur = (left + right) / 2;
    if (mas[cur].GetKey() > k)
    {
      right = cur - 1;
    }
    else if (mas[cur].GetKey() < k)
    {
      left = cur + 1;
    }
      else
        return mas[cur];
    }
    return not_find;
  }
//.........................................................
template <class T>
void TSortTable<T>::Resize(int _size)
{
  if (_size <= size)
    throw TException("Error size");
  TElem<T>* new_mas = new TElem<T>[_size];
  for (int i = 0; i < size; i++)
    new_mas[i] = mas[i];
  delete[]mas;
  mas = new_mas;
  size = _size;
}
//.........................................................
template <class T>
T& TSortTable<T>::operator[](string k)
{
  TElem<T> &tmp = Search(k);
  if (tmp == not_find)
  {
    T a;
    cout << "Enter the data:\n";
    cin >> a;
    int T = Put(k,a);
    return mas[T].GetData();
  }
  else return tmp.GetData();
}
//.........................................................
template <class T>
int TSortTable<T>::GetCount()
{
  return count;
}
//.........................................................
template <class T>
int TSortTable<T>::GetSize()
{
  return size;
}