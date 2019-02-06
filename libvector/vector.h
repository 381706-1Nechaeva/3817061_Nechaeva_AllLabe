#pragma once
#include <iostream>
#include <math.h>
using namespace std;
template <class T>

class TVector
{
protected:
	T* vector;
	int size; //размер вектора
	int FirstInd; // стартовый индекс
public:
  TVector(const TVector<T> &A); //конструктор копирования
	TVector(int _size = 5, int _FirstInd = 0); //конструктор инициализации
	~TVector();
	int GetSize(); // получить размер вектора
  int GetFirstInd(); // получить стартовый индекс
	TVector<T>& operator=(const TVector<T> &A); //присваивание
	T& operator[](int i); //индексация
	bool operator==(const TVector<T> &A); //сравнение
	bool operator!=(const TVector<T> &A); //сравнение
	//скалярные операции
	TVector<T> operator*(const T &a); // умножение на число
	TVector<T> operator+(const T &a); //прибавление числа
	TVector<T> operator-(const T &a); //вычитание числа
	//векторные операции
	TVector<T> operator+(const TVector<T> &A); //сложение
	TVector<T> operator-(const TVector<T> &A); //вычитание
	T operator*(const TVector<T> &A); //умножение

	friend istream &operator>>(istream& A, TVector& B)
	{
		for (int i = 0; i < B.size; i++)
			A >> B.vector[i];
		return A;
	}
	friend ostream &operator<<(ostream& A,const TVector& B)
	{
		for (int i = 0; i < B.size; i++)
			A << B.vector[i] << "\t";
		A << "\n";
		return A;
	}
};
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(int _size, int _FirstInd)
{
	if (_size < 0)
		throw - 1;
	else
	{
		if (_size == 0)
		{
			size = 0;
			vector = NULL;
		}
		else
		{
			if ((_FirstInd < 0) || (_FirstInd >= _size))
				throw - 1;
			else
			{
				size = _size - _FirstInd;
				FirstInd = _FirstInd;
				vector = new T[size];
				for (int i = 0; i < size; i++)
					vector[i] = 0;
			}
		}
	}
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(const TVector<T> &A)
{
	size = A.size;
	FirstInd = A.FirstInd;
	if (size != 0)
	{
		vector = new T[size];
		for (int i = 0; i < size; i++)
			vector[i] = A.vector[i];
	}
	else
		vector = 0;
}

// ---------------------------------------------------------------------------
template <class T>
TVector<T>::~TVector()
{
	size = 0;
	if (vector != 0)
		delete[] vector;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetSize()
{
	return size;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetFirstInd()
{
	return FirstInd;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &A)
{
	TVector<T> S(*this);
	if (size == A.size)
	{
		if (size == 0)
			S.vector = 0;
		else
		{
			S.size = size;
			S.vector = new T[size];
			for (int i = 0; i < size; i++)
				S.vector[i] = vector[i] + A.vector[i];
      
		}
	}
	else
		throw 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A)
{
	TVector<T> S(*this);
	if (size == A.size)
	{
		if (size == 0)
			S.vector = 0;
		else
		{
			S.size = size;
			S.vector = new T[size];
			for (int i = 0; i < size; i++)
				S.vector[i] = vector[i] - A.vector[i];
		}
	}
	else
		throw - 1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
T TVector<T>::operator*(const TVector<T> &A)
{
	T summ = 0;
	if (size == A.size)
	{
		if (size == 0)
			return summ;
		else
		{
			for (int i = 0; i < size; i++)
				summ += vector[i] * A.vector[i];
		}
	}
	else
		throw 1;
	return summ;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(const T &a)
{
	TVector<T> S;
	if (size == 0)
		S.vector = 0;
	else
	{
		S.size = size;
		S.vector = new T[size];
		for (int i = 0; i < size; i++)
			S.vector[i] = vector[i] * a;
	}
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const T &a)
{
	TVector<T> S;
	if (size == 0)
		S.vector = 0;
	else
	{
		S.size = size;
		S.vector = new T[size];
		for (int i = 0; i < size; i++)
			S.vector[i] = vector[i] + a;
	}
   return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const T &a)
{
	TVector<T> S;
	if (size == 0)
		S.vector = 0;
	else
	{
		S.size = size;
		S.vector = new T[size];
		for (int i = 0; i < size; i++)
			S.vector[i] = vector[i] - a;
	}
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &A)
{
	if (this != &A)
	{
		size = A.size;
		FirstInd = A.FirstInd;
		if (size != 0)
		{
			if (vector != 0)
				delete[]vector;
			vector = new T[size];
			for (int i = 0; i < size; i++)
				vector[i] = A.vector[i];
		}
	}
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int i)
{
	if ((i < 0) || (i >= size + FirstInd))
		throw - 1;
	else
		return vector[i - FirstInd];
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator==(const TVector<T> &A)
{
	int res = 1;
	if (size == A.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (vector[i] != A.vector[i])
			{
				res = 0;
				break;
			}
		}
	}
	else
	{
		res = 0;
	}
	return res;
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator!=(const TVector<T> &A)
{

	return !(*this == A);
}

template <class T>

class TMatrix : public TVector <TVector<T> >
{
public:
	TMatrix(int _n = 3);
	TMatrix(const TMatrix<T>  &A);
	TMatrix(const TVector<TVector<T> > &A); // конструктор преобразования типа
	bool operator==(const TMatrix<T> &A); //сравнение
	bool operator!=(const TMatrix<T> &A); //сравнение
	TMatrix& operator=(const TMatrix<T> &A); //присваивание
	TMatrix operator+(const TMatrix<T> &A); //сложение матриц
	TMatrix operator-(const TMatrix<T> &A); // вычитание
	TMatrix operator*(const TMatrix<T> &A); // умножение матриц
  TMatrix operator/(const TMatrix<T> &A); // деление матриц

	//ввод/вывод в поток

	friend istream &operator>>(istream& A, TMatrix& B)
	{
		for (int i = 0; i < B.size; i++)
			A >> B.vector[i];
		return A;
	}
	friend ostream &operator<<(ostream& A, const TMatrix& B)
	{
		for (int j = 0; j < B.size; j++)
		{
			for (int i = 0; i < B.vector[j].GetFirstInd(); i++)
				A << "\t";
			A << B.vector[j] << "\n";
		}
		return A;
	}
};
//............................................................
template <class T>
TMatrix<T>::TMatrix(int _n) : TVector<TVector<T> >(_n)
{
	if (_n < 1)
		throw 1;
	for (int i = 0; i < _n; i++)
		this->vector[i] = TVector<T>(_n, i);
}
//............................................................
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &A) : TVector<TVector<T> >(A)
{
}
//............................................................
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > & A) : TVector<TVector<T> >(A)
{
}
//............................................................
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &A)
{
	return TVector<TVector<T> >:: operator==(A);
}
//............................................................
template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &A)
{
	return !(*this == A);
}
//............................................................
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &A)
{
	if (this != &A)
	{
		this->size = A.size;
		this->FirstInd = A.FirstInd;
		if (this->size != 0)
		{
			if (this->vector != 0)
				delete[]this->vector;
			this->vector = new TVector<T>[this->size];
			for (int i = 0; i < this->size; i++)
				this->vector[i] = A.vector[i];
		}
	}
	return *this;
}
//............................................................
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &A)
{
	return TVector<TVector<T> >::operator+(A);
}
//............................................................
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &A)
{
	return TVector<TVector<T> >::operator-(A);
}
//............................................................
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &A)
{
	TMatrix<T> temp(this->size);
	if (this->size == A.size)
	{
		for (int i = 0; i < temp.size; i++)
		{
			for (int j = i; j < temp.size; j++)
			{
				for (int k = 0; k < A.vector[j].GetFirstInd()+1; k++)
				{
					if ((j >= A.vector[j].GetFirstInd()) && (k >= A.vector[i].GetFirstInd()))
					{
						temp.vector[i][j] += this->vector[i][k] * A.vector[k][j];
					}
				}
			}
		}
	return temp;			
	}
	else
		throw 1;
	
}
//............................................................
template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &A)
{
  if (this->size == A.size)
  {
    TMatrix <T> copy(*this);
    TMatrix <T> rez(A);
    TMatrix <T> edin(this->size), temp(this->size);
    T a, r;
    for (int i = 0; i < this->size; i++)
    {
      for (int j = i; j < this->size; j++)
      {
        if (i == j)
          edin[i][j] = 1;
        else
          edin[i][j] = 0;
      }
    }
    for (int i = 0; i < this->size; i++)
    {
      for (int j = 0; j < this->size; j++)
      {
        if (i != j)
        {
          if (j >= rez.vector[i].GetFirstInd() && j >= rez.vector[j].GetFirstInd())
          {
            r = rez[i][j] / rez[j][j];
            for (int k = 0; k < this->size; k++)
            {
              if (k >= rez.vector[k].GetFirstInd() && k >= rez.vector[j].GetFirstInd())
              {
                edin[i][k] -= r * edin[j][k];
                rez[i][k] -= r * rez[j][k];
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < this->size; i++)
    {
      if (i >= rez.vector[i].GetFirstInd())
        a = rez[i][i];
      for (int j = 0; j < this->size; j++)
      {
        if (j >= rez.vector[j].GetFirstInd() && j >= rez.vector[i].GetFirstInd())
          edin[i][j] /= a;
      }
    }
    temp = copy * edin;
    return temp;
  }
  else
    throw - 1;
}