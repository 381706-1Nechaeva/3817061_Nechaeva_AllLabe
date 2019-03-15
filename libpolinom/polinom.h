#pragma once
#include "monom.h"

class TPolynom
{
protected:
  TMonom *begin;  //��������� �� ������ ����� � ��������
  int count;  //���������� ���������� � ������ ������
  int size;  //���������� ������� � �������� 
public:
  TPolynom(int _count = 3);
  TPolynom(const TPolynom &A);
  ~TPolynom();

  int GetSize();  //�������� ����� ������� � ��������
  TMonom* GetBegin();  //�������� ����� ������� ������ � ��������

  TPolynom operator+(const TPolynom &A);
  TPolynom operator-(const TPolynom &A);
  TPolynom operator*(const TPolynom &A);
  TPolynom& operator=(const TPolynom &A);
  bool operator==(const TPolynom &A);

  void Put(const TMonom &A);

  friend ostream& operator<<(ostream& ostr, TPolynom &A);
};
