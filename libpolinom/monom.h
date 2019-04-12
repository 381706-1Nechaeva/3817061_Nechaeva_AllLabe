#pragma once
#include "throws.h"
#include <iostream>

class TMonom
{
protected:
  TMonom* next;  //��������� �� ��������� �����
  int *deg;  //������ �������� � ������
  double koeff;  //�����������
  int count;  //���������� ���������� � ������

public:
  TMonom();
  TMonom(int* _deg, double _koeff,int _count=3);
  TMonom(const TMonom &A);
  ~TMonom();

  void SetNext(TMonom* _next);  //���������� ����� ���������� ������
  void SetDeg(int* _deg);  //���������� ������ �������� ������
  void SetKoef(double _koeff);  //���������� ����������� ��� ������
  void SetCount(int _count);  //���������� ���������� ���������� � ������

  TMonom* GetNext();  //�������� ����� ���������� ������
  int* GetDeg();  //�������� ������ �������� ������
  double GetKoeff() const;  //�������� ����������� ��� ������
  int GetCount() const;  //�������� ���������� ���������� � ������

  TMonom operator+(const TMonom &A);
  TMonom& operator+=(const TMonom &A);
  TMonom operator-(const TMonom &A);
  TMonom& operator-=(const TMonom &A);
  TMonom operator*(const TMonom &A);
  TMonom& operator*=(const TMonom &A);
  TMonom& operator=(const TMonom &A);
  bool operator==(const TMonom &A);
  bool operator>(const TMonom &A);
  bool operator<(const TMonom &A);

  friend istream& operator>>(istream& istr, TMonom &A);
  friend ostream& operator<<(ostream& ostr, TMonom &A);
};
