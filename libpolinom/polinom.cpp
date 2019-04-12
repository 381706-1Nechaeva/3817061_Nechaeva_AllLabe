#include "polinom.h"

//.....................................................
TPolynom::TPolynom(int _count)
{
  if (_count < 0)
    throw TException("Error count");
  count = _count;
  size = 0;
  begin = 0;
}
//.....................................................
TPolynom::TPolynom(const TPolynom &A)
{
  count = A.count;
  size = A.size;
  if (A.begin == 0)
    begin = 0;
  else
  {
    begin = new TMonom(*A.begin);
    TMonom *abegin = A.begin, *temp = begin;
    while (abegin->GetNext() != 0)
    {
      temp->SetNext(new TMonom(*abegin->GetNext()));
      temp = temp->GetNext();
      abegin = abegin->GetNext();
    }
    temp->SetNext(NULL);
  }
}
//.....................................................
TPolynom::~TPolynom()
{
}
//.....................................................
int TPolynom::GetSize()
{
  return size;
}
//.....................................................
TMonom* TPolynom::GetBegin()
{
  return begin;
}
//.....................................................
void TPolynom::Put(const TMonom &A)
{
  if (this->count != A.GetCount())
    throw TException("Different count");
  if (A.GetKoeff() == 0)
    throw TException("zero");
  if (begin == 0)
  {
    begin = new TMonom(A);
    size++;
  }
  else
  {
    TMonom *start = begin, *end = begin->GetNext();
    TMonom *temp = new TMonom(A);
    if (*start < A)
    {
      temp->SetNext(start);
      begin = temp;
    }
    else if (*start == A)
    {
      if (A.GetKoeff() < 0)
        *begin -= A;
      else
        *begin += A;
      if (begin->GetKoeff() == 0)
      {
        delete begin;
        begin = temp;
        size--;
      }
    }
    else
    {
      while (end != 0)
      {
        if (*end == A)
        {
          if (A.GetKoeff() < 0)
            *end -= A;
          else
            *end += A;
          if (end->GetKoeff() == 0)
          {
            start->SetNext(end->GetNext());
            delete[] end;
            size--;
          }
        }
        if (*end < A)
        {
          start->SetNext(temp);
          temp->SetNext(end);
        }
        start = end;
        end = end->GetNext();
      }
      start->SetNext(new TMonom(A));
      
    }
   // delete temp;
    size++;
  }
}
//.....................................................
TPolynom TPolynom::operator+(const TPolynom &A)
{
    if (this->count != A.count)
      throw TException("Different count");
    TPolynom res(count);
    TMonom *tmon1 = begin, *tmon2 = A.begin, *tmon = res.begin;
      while ((tmon1 != 0) && (tmon2 != 0))
      {
        TMonom *temp;
        if ((*tmon1) == (*tmon2))
        {
          TMonom k = (*tmon1);
          k += (*tmon2);
          temp = new TMonom(k);
          if (temp->GetKoeff() == 0)
            continue;
          tmon1 = tmon1->GetNext();
          tmon2 = tmon2->GetNext();
        }
        else if ((*tmon1) < (*tmon2))
        {
          temp = new TMonom((*tmon2));
          if (temp->GetKoeff() == 0)
            continue;
          tmon2 = tmon2->GetNext();
        }
        else if ((*tmon1) > (*tmon2))
        {
          temp = new TMonom((*tmon1));
          if (temp->GetKoeff() == 0)
            continue;
          tmon1 = tmon1->GetNext();
        }
        if (tmon == 0)
        {
          tmon = temp;
          res.begin = temp;
          res.size++;
        }
        else
        {
          tmon->SetNext(temp);
          res.size++;
          tmon = tmon->GetNext();
        }
      }
      if (tmon1 == 0)
        tmon1 = tmon2;
      while (tmon1 != 0)
      {
        if (tmon1->GetKoeff() == 0)
          continue;
        tmon->SetNext(new TMonom(*tmon1));
        tmon1 = tmon1->GetNext();
        res.size++;
        tmon = tmon->GetNext();
      }
    return res;
}
//.....................................................
TPolynom TPolynom::operator-(const TPolynom &A)
{
  if (this->count != A.count)
    throw TException("Different count");

  TPolynom res(count);
  TMonom *tmon1 = begin, *tmon2 = A.begin, *tmon = res.begin;
  while ((tmon1 != 0) && (tmon2 != 0))
  {
    TMonom *temp;
    if ((*tmon1) == (*tmon2))
    {
      TMonom k = (*tmon1);
      k -= (*tmon2);
      temp = new TMonom(k);
      tmon1 = tmon1->GetNext();
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) < (*tmon2))
    {
      temp = new TMonom((*tmon2));
      if (temp->GetKoeff() == 0)
        continue;
      temp->SetKoef(temp->GetKoeff() * (-1));
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) > (*tmon2))
    {
      temp = new TMonom((*tmon1));
      if (temp->GetKoeff() == 0)
        continue;
      tmon1 = tmon1->GetNext();
    }
    if (temp->GetKoeff() == 0)
      continue;
    if (tmon == 0)
    {
      tmon = temp;
      res.begin = temp;
      res.size++;
    }
    else
    {
      tmon->SetNext(temp);
      res.size++;
      tmon = tmon->GetNext();
    }
  }
  while (tmon1 != 0)
  {
    if (tmon1->GetKoeff() == 0)
      continue;
    tmon->SetNext(new TMonom(*tmon1));
    tmon1 = tmon1->GetNext();
    res.size++;
    tmon = tmon->GetNext();
  }
  while (tmon2 != 0)
  {
    if (tmon2->GetKoeff() == 0)
      continue;
    TMonom t(*tmon2);
    t.SetKoef(t.GetKoeff() * (-1));
    tmon->SetNext(&t);
    tmon2 = tmon2->GetNext();
    res.size++;
    tmon = tmon->GetNext();
  }
  return res;
}
//.....................................................
TPolynom TPolynom::operator*(const TPolynom &A)
{
  if (this->count != A.count)
    throw TException("Different count");
  TPolynom res(count);
  TMonom *_st = begin;
  TMonom *_pst = A.begin;
  while (_st != 0)
  {
    if (_st->GetKoeff() == 0)
      continue;
    while (_pst != 0)
    {
      if (_pst->GetKoeff() == 0)
        continue;
      TMonom k = (*_st);
      int a = k.GetKoeff();
      int b = _pst->GetKoeff();
      int* degr=new int[count];
      int* deg = k.GetDeg();
      int* Adeg = _pst->GetDeg();
      for (int i = 0; i < count; i++)
        degr[i] = deg[i] + Adeg[i];
      TMonom* f = new TMonom(degr, a*b, count);
      f->SetNext(NULL);
      res.Put(*f);
      _pst = _pst->GetNext();
    }
    _st = _st->GetNext();
    _pst = A.begin;
  }
  return res;
}
//------------------------------------------------------------------------------
TPolynom& TPolynom::operator=(const TPolynom &A)
{
  if (this == &A)
    throw TException("Same polynoms");
  if (this->count != A.count)
    throw TException("Different count");
  else
  {
    size = A.size;
    TMonom *buf1 = begin, *buf2 = begin;
    while (buf1 != 0)
    {
      buf1 = buf1->GetNext();
      delete buf2;
      buf2 = buf1;
    }
    buf1 = A.begin->GetNext();
    buf2 = new TMonom(*A.begin);
    begin = buf2;
    while (buf1 != 0)
    {
      buf2->SetNext(new TMonom(*buf1));
      buf2 = buf2->GetNext();
      buf1 = buf1->GetNext();
    }
    return *this;
  }
}

//------------------------------------------------------------------------------
bool TPolynom::operator==(const TPolynom &A)
{
  if (this->count != A.count)
    throw TException("Different count");
  if (this->size != A.size)
    return false;
  TMonom* tmon1 = begin;
  TMonom* tmon2 = A.begin;
  while (tmon1 != 0)
  {
    if (!(*tmon1 == *tmon2))
      return false;
    if (tmon1->GetKoeff() != tmon2->GetKoeff())
      return false;
    tmon1 = tmon1->GetNext();
    tmon2 = tmon2->GetNext();
  }
  return true;
}

//------------------------------------------------------------------------------
ostream& operator<<(ostream& ostr, TPolynom& pol)
{
  TMonom *tmp = pol.begin;
  if (tmp != 0)
  {
    ostr << *tmp;
    tmp = tmp->GetNext();
  }
  while (tmp != 0)
  {
    if (tmp->GetKoeff() > 0)
      ostr << " + " << *tmp;
    else
      ostr << " " << *tmp;
    tmp = tmp->GetNext();
  }
  return ostr;
}

































//НЕЧАЙКИНА