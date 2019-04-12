#pragma once
#include "throws.h"
#include <iostream>

class TMonom
{
protected:
  TMonom* next;  //указатель на следующий моном
  int *deg;  //массив степеней в мономе
  double koeff;  //коэффициент
  int count;  //количество переменных в мономе

public:
  TMonom();
  TMonom(int* _deg, double _koeff,int _count=3);
  TMonom(const TMonom &A);
  ~TMonom();

  void SetNext(TMonom* _next);  //установить адрес следующего монома
  void SetDeg(int* _deg);  //установить массив степеней монома
  void SetKoef(double _koeff);  //установить коэффициент при мономе
  void SetCount(int _count);  //установить количество переменных в мономе

  TMonom* GetNext();  //получить адрес следующего монома
  int* GetDeg();  //получить массив степеней монома
  double GetKoeff() const;  //получить коэффициент при мономе
  int GetCount() const;  //получить количество переменных в мономе

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
