#pragma once
#include "queue.h"
#include "throws.h"

template <class T>
class TArrList {
private:
  T* mas;
  int size; //������ ������
  int count; //���������� ��������� � ������
  int start; //������ ������� �������� ������
  int finish; //������ ���������� �������� ������
  int *next_ind; //������ ��������, ����������� �� ��������� ������� ������
  int *prev_ind; //������ ��������, ����������� �� ���������� ������� ������
  TQueue<int> elem; //������� �������� ��� ���������� ������ ����� � �������
public:
  TArrList(int _size = 10);//����������� �������������
  TArrList(TArrList<T> &A); //����������� �����������
  ~TArrList();    //����������
  void PutBegin(const T &a); //�������� � ������ ������
  void PutEnd(const T &a);  //�������� � ����� ������ 
  void PutTek(const T &a, int n); //�������� � ����� ����� ������
  T GetBegin();  //������� �� ������ ������ � ����������� ���������
  T GetEnd();    //������� �� ����� ������ � ����������� ���������
  T GetTek(int n); //������� �� ������ ����� ������ � ���������� ���������
  bool IsFull() { return count == size; }  //�������� �� �������
  bool IsEmpty() { return count == 0; }  //�������� �� �������
  void PrintArr(); //������ ������
};
//...........................................................
template <class T>
TArrList<T>::TArrList(int _size)
{
  if (_size <= 0)
    throw TException("error size");
  else
  {
    size = _size;
    count = 0;
    start = -1;
    finish = -1;
    mas = new T[size];
    next_ind = new int[size];
    prev_ind = new int[size];
    for (int i = 0; i < size; i++)
    {
      next_ind[i] = -2;
      prev_ind[i] = -2;
      elem.Put(i);
    }
  }
}
//...........................................................
template <class T>
TArrList<T>::TArrList(TArrList<T> &A)
{
  size = A.size;
  count = A.count;
  start = A.start;
  finish = A.finish;
  mas = new T[size];
  next_ind = new int[size];
  prev_ind = new int[size];
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    next_ind[i] = A.next_ind[i];
    prev_ind[i] = A.prev_ind[i];
    elem.Put(A.elem.Get());
  }
}
//...........................................................
template <class T>
TArrList<T>::~TArrList()
{
  delete[] mas;
  delete[] next_ind;
  delete[] prev_ind;
}
//...........................................................
template <class T>
void TArrList<T>::PutBegin(const T &a)
{
  if (IsFull())
    throw TException("ArrList is full");
  int free_elem = elem.Get();
  mas[free_elem] = a;
  next_ind[free_elem] = start;
  if (start != -1)
    prev_ind[start] = free_elem;
  else
    finish = free_elem;
  start = free_elem;
  count++;
}
//...........................................................
template <class T>
void TArrList<T>::PutEnd(const T &a)
{
  if (IsFull())
    throw TException("ArrList is full");
  int free_elem = elem.Get();
  mas[free_elem] = a;
  prev_ind[free_elem] = finish;
  if (finish != -1)
    next_ind[finish] = free_elem;
  else
    start = free_elem;
  finish = free_elem;
  count++;
}
//...........................................................
template <class T>
void TArrList<T>::PrintArr()
{
  if (IsEmpty())
    throw TException("ArrList is empty");
  int j = 0;
  for (int i = start; j < count; i = next_ind[i])
  {
    cout << mas[i] << "\t";
    j++;
  }
}
//...........................................................
template <class T>
T TArrList<T>::GetBegin()
{
  if (IsEmpty())
    throw TException("ArrList is empty");
  T rez = mas[start];
  elem.Put(start);
  int temp = next_ind[start];
  prev_ind[temp] = -2;
  start = temp;
  count--;
  return rez;
}
//...........................................................
template <class T>
T TArrList<T>::GetEnd()
{
  if (IsEmpty())
    throw TException("ArrList is empty");
  T rez = mas[finish];
  elem.Put(finish);
  int temp = prev_ind[finish];
  next_ind[temp] = -2;
  finish = temp;
  count--;
  return rez;
}
//...........................................................
template <class T>
void TArrList<T>::PutTek(const T &a, int n)
{
  if (IsFull() || count == 1)
    throw TException("ArrList is empty or have one element");
  if (n == count || n <= 0 || n > size)
    throw TException("Error number");
  int j = 0;
  int temp = start;
  for (int i = start; j < n; i = next_ind[i])
  {
    temp = i;
    j++;
  }
  int free_elem = elem.Get();
  mas[free_elem] = a;
  int tempind = next_ind[temp];
  next_ind[temp] = free_elem;
  next_ind[free_elem] = tempind;
  prev_ind[tempind] = free_elem;
  prev_ind[free_elem] = temp;
  count++;
}
//...........................................................
template <class T>
T TArrList<T>::GetTek(int n)
{
  if (IsEmpty() || count <= 2)
    throw TException("ArrList is empty or have one element");
  if (n == count || n <= 0 || n > size)
    throw TException("Error number");
  int temp = start, j = 0;
  for (int i = start; j <= n; i = next_ind[i])
  {
    temp = i;
    j++;
  }
  T rez = mas[temp];
  elem.Put(temp);
  int tempprev = prev_ind[temp];
  int tempnext = next_ind[temp];
  next_ind[tempprev] = tempnext;
  prev_ind[tempnext] = tempprev;
  count--;
  return rez;
}
