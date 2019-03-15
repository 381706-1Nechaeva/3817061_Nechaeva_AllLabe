#include "monom.h"

TMonom::TMonom()
{
    count = 4;
    koeff = 4;
    next = 0;
    deg = new int[count];
}
  TMonom::TMonom(int* _deg, double _koeff, int _count)
  {
    if (_count < 0)
      throw TException("Error count");
    if (_count == 0)
    {
      count = 0;
      deg = NULL;
      next = NULL;
      koeff = _koeff;
    }
    else
    {
      count = _count;
      koeff = _koeff;
      next = 0;
      deg = new int[count];
      for (int i = 0; i < count; i++)
        if (_deg[i] >= 0)
          deg[i] = _deg[i];
        else
          throw TException("Error deg");
    }
  }
  //.......................................
  TMonom::TMonom(const TMonom &A)
  {
    count = A.count;
    koeff = A.koeff;
    next = A.next;
    deg = new int[count];
    for (int i = 0; i < count; i++)
      deg[i] = A.deg[i];
  }
  //.......................................
  TMonom::~TMonom()
  {
    if (deg != 0)
      delete[] deg;
  }
  void TMonom::SetNext(TMonom* _next)
  {
    next = _next;
  }
  //.......................................
  void TMonom::SetDeg(int* _deg)
  {
    for (int i = 0; i < count; i++)
      if (_deg[i] >= 0)
        deg[i] = _deg[i];
      else
        throw TException("Error deg");
  }
  //.......................................
  void TMonom::SetKoef(double _koeff)
  {
    koeff = _koeff;
  }
  //.......................................
  void TMonom::SetCount(int _count)
  {
    if (_count < 0 || _count == count)
      throw TException("Error count");
    if (_count == 0)
      if (deg != 0)
      {
        delete[] deg;
        deg = NULL;
        count = 0;
      }
      if(_count>0)
      {
        int* temp = new int[count];
        for (int i = 0; i < count; i++)
          temp[i] = deg[i];
        delete[] deg;
        deg = new int[_count];
        if (_count > count)
        {
          int i = 0;
          for (; i < count; i++)
            deg[i] = temp[i];
          for (; i < _count; i++)
            deg[i] = 0;
        }
        else
          for (int i = 0; i < _count; i++)
            deg[i] = temp[i];
        count = _count;
      }
  }
  //.......................................
  TMonom* TMonom::GetNext()
  {
    return next;
  }
  //.......................................
  int* TMonom::GetDeg()
  {
    return deg;
  }
  //.......................................
  double TMonom::GetKoeff() const
  {
    return koeff;
  }
  //.......................................
  int TMonom::GetCount() const
  {
    return count;
  }
  //.......................................
  TMonom TMonom::operator+(const TMonom &A)
  {
    if (*this == A)
    {
      TMonom temp(A);
      temp.koeff = koeff + A.koeff;
      return temp;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom& TMonom::operator+=(const TMonom &A)
  {
    if (*this == A)
    {
      koeff += A.koeff;
      return *this;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom TMonom::operator-(const TMonom &A)
  {
    if (*this == A)
    {
      TMonom temp(A);
      temp.koeff = koeff - A.koeff;
      return temp;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom& TMonom::operator-=(const TMonom &A)
  {
    if (*this == A)
    {
      koeff -= A.koeff;
      return *this;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom TMonom::operator*(const TMonom &A)
  {
    if (*this == A)
    {
      TMonom temp(A);
      temp.koeff = koeff * A.koeff;
      for (int i = 0; i < count; i++)
        temp.deg[i] = deg[i] + A.deg[i];
      return temp;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom& TMonom::operator*=(const TMonom &A)
  {
    if (*this == A)
    {
      koeff *= A.koeff;
      for (int i = 0; i < count; i++)
        deg[i] += A.deg[i];
      return *this;
    }
    else
      throw TException("Different monoms");
  }
  //.......................................
  TMonom& TMonom::operator=(const TMonom &A)
  {
    if (count == A.count) {
      if (*this == A)
        throw TException("The same monoms");
    }
    count = A.count;
    next = A.next;
    koeff = A.koeff;
    delete[] deg;
    deg = new int[count];
    for (int i = 0; i < count; i++)
      deg[i] = A.deg[i];
    return *this;
  }
  //.......................................
  bool TMonom::operator==(const TMonom &A)
  {
      if (count != A.count)
        throw TException("Error count");
      for (int i = 0; i < count; i++)
        if (deg[i] != A.deg[i])
          return false;
      return true;
  }
  //.......................................
  bool TMonom::operator>(const TMonom &A)
  {
    if (count != A.count)
      throw TException("Error count");
    if (*this == A)
      throw TException("The same monoms");
    for (int i = 0; i < count; i++)
    {
      if (deg[i] == A.deg[i])
        continue;
      else if (deg[i] < A.deg[i])
        return false;
      else return true;
    }
    if (koeff > A.koeff)
      return true;
    else return false;
  }
  //.......................................
  bool TMonom::operator<(const TMonom &A)
  {
    if (count != A.count)
      throw TException("Error count");

    if (*this == A)
      throw TException("The same monoms");
    for (int i = 0; i < count; i++)
    {
      if (deg[i] == A.deg[i])
        continue;
      else if (deg[i] > A.deg[i])
        return false;
      else return true;
    }
    if (koeff < A.koeff)
      return true;
    else return false;
  }
  //.......................................
  istream& operator>>(istream& istr, TMonom &A)
  {
    istr >> A.koeff;
    for (int i = 0; i < A.count; i++)
      istr >> A.deg[i];
    return istr;
  }
  //.......................................
  ostream& operator<<(ostream& ostr, TMonom &A)
  {
    ostr << A.koeff;
    if (A.koeff != 0)
    {
      for (int i = 0; i < A.count; i++)
        if (A.deg[i] != 0)
        {
          ostr << "x" << i;
          if (A.deg[i] != 1)
            ostr << "^" << A.deg[i];
        }
    }
    return ostr;
  }