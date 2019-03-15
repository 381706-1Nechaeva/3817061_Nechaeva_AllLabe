#pragma once
#include "monom.h"

class TPolynom
{
protected:
  TMonom *begin;  //указатель на первый моном в полиноме
  int count;  //количество переменных в каждом мономе
  int size;  //количество мономов в полиноме 
public:
  TPolynom(int _count = 3);
  TPolynom(const TPolynom &A);
  ~TPolynom();

  int GetSize();  //получить число мономов в полиноме
  TMonom* GetBegin();  //получить адрес первого монома в полиноме

  TPolynom operator+(const TPolynom &A);
  TPolynom operator-(const TPolynom &A);
  TPolynom operator*(const TPolynom &A);
  TPolynom& operator=(const TPolynom &A);
  bool operator==(const TPolynom &A);

  void Put(const TMonom &A);

  friend ostream& operator<<(ostream& ostr, TPolynom &A);
};
