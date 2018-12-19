#pragma once
#include "queue.h"

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
  TQueue <int> free_elem; //������� ��������� ��������� - ��� ���������� "������" ����� � �������, 
                         //���������� ����� �������� ��������
public:
  TArrList(int _size = 5); //����������� �������������
  TArrList(TArrList<T> &A); //����������� �����������
  void PutStart(const T &a); //�������� � ������ ������
  void PutEnd(const T &a);  //�������� � ����� ������ 
  T GetStart();  //������� �� ������ ������ � ����������� ���������
  T GetEnd();    //������� �� ����� ������ � ����������� ���������
  bool IsFull();  //�������� �� �������
  bool IsEmpty();  //�������� �� �������
};
//...........................................................
template <class T>
TArrList<T>::TArrList(int _size)
{
  if (_size <= 0)
    throw - 1;
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
      nextInd[i] = -2;
      prevInd[i] = -2;
      free_elem.Put(i);
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
  free_elem = A.free_elem;
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    next_ind[i] = A.next_ind[i];
    prev_ind[i] = A.prev_ind[i];
  }
}
//...........................................................
template <class T>
void TArrList<T>::PutStart(const T &a)
{
  if (IsFull())
    throw - 1;
  int first_free_elem = free_elem.Get();
  mas[first_free_elem] = a;
  next_ind[first_free_elem] = start;
  if (start != -1)
    prev_ind[start] = first_free_elem;
  else
    finish = first_free_elem;
  start = first_free_elem;
  count++;
}
