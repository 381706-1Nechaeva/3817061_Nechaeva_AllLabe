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
	TVector(const TVector &A); //конструктор копирования
	TVector(int _size = 5, int _FirstInd = 0); //конструктор инициализации
	~TVector();
	int GetSize(); // получить размер вектора
	int GetFirstInd(); // получить стартовый индекс
	TVector<T>& operator=(const TVector &A); //присваивание
	T& operator[](int i); //индексация
	bool operator==(const TVector &A); //сравнение
	bool operator!=(const TVector &A); //сравнение
	//скалярные операции
	TVector<T> operator*(const T &a); // умножение на число
	TVector<T> operator+(const T &a); //прибавление числа
	TVector<T> operator-(const T &a); //вычитание числа
	//векторные операции
	TVector<T> operator+(const TVector &A); //сложение
	TVector<T> operator-(const TVector &A); //вычитание
	TVector<T> operator*(const TVector &A); //умножение

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
	if (_size <= 0)
		throw - 1;
	if ((_FirstInd < 0) || (_FirstInd >= _size))
		throw - 1;
	size = _size - _FirstInd;
	FirstInd = _FirstInd;
	vector = new T[size];
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(const TVector &A)
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
		delete[]vector;
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
TVector<T> TVector<T>::operator+(const TVector &A)
{
	TVector<T> S;
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
TVector<T> TVector<T>::operator-(const TVector &A)
{
	TVector<T> S;
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
TVector<T> TVector<T>::operator*(const TVector &A)
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
TVector<T>& TVector<T>::operator=(const TVector &A)
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
	if (i >= 0 && i <= size)
		return vector[i];
	else
		throw - 1;
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator==(const TVector &A)
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
	return res;
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator!=(const TVector &A)
{

	return !(*this == A);
}

template <class T>

class TMatrix : public TVector <TVector<T> >
{
public:
	TMatrix(int _n = 3);
	TMatrix(const TMatrix  &A);
	TMatrix(const TVector<TVector<T> > &A);
	bool operator==(const TMatrix &A); //сравнение
	bool operator!=(const TMatrix &A); //сравнение
	TMatrix& operator=(const TMatrix &A); // 
	TMatrix operator+(const TMatrix &A); // 
	TMatrix operator-(const TMatrix &A); // 
	//TMatrix operator*(TMatrix<T> &A); // 

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
TMatrix<T>::TMatrix(const TMatrix &A) : TVector<TVector<T> >(A)
{
}
//............................................................
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > & A) : TVector<TVector<T> >(A)
{
}
//............................................................
template <class T>
bool TMatrix<T>::operator==(const TMatrix &A)
{
	return TVector<TVector<T> >:: operator==(A);
}
//............................................................
template <class T>
bool TMatrix<T>::operator!=(const TMatrix &A)
{
	return !(*this == A);
}
//............................................................
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix &A)
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
TMatrix<T> TMatrix<T>::operator+(const TMatrix &A)
{
	return TVector<TVector<T> >::operator+(A);
}
//............................................................
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix &A)
{
	return TVector<TVector<T> >::operator-(A);
}