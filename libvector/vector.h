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
	int FirstInd; // начальный индекс вектора
public:
	TVector( TVector &A); //конструктор копирования
	TVector(int _size = 5, int _FirstInd=0 ); //конструктор инициализацции
	~TVector();
	int GetSize(); // размер вектора
	int GetFirstInd(); // индекс первого элемента вектора
	TVector<T>& operator=(TVector<T> &A); //присваивание
	T& operator[](int i); //индексация
	bool operator==(TVector<T> &A); //сравнение
	bool operator!=(TVector<T> &A); //сравнение
	//Скалярные вычисления
	TVector<T> operator*( T a); //умножение на число +
	TVector<T> operator+( T a); //сложить число + 
	TVector<T> operator-( T a); //вычесть число +
	//Векторные вычисления
	TVector<T> operator+(TVector<T> &A); //сложение
	TVector<T> operator-(TVector<T> &A); //вычитание
	TVector<T> operator*(TVector<T> &A); //умножение

	friend istream &operator>>(istream& A, TVector& B)
	{
		for (int i = 0; i < B.size; i++)
			A >> B.vector[i];
		return A;
	}
	friend ostream &operator<<(ostream& A, TVector& B)
	{
		for (int i = 0; i < B.size; i++)
			A << B.vector[i]<<"\t";
		A << "\n";
		return A;
	}
};
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(int _size, int _FirstInd)
{
	if (_size <= 0)
		throw -1;
	if ((_FirstInd < 0) || (_FirstInd >= _size))
		throw -1;
	size = _size - _FirstInd;
	FirstInd = _FirstInd;
	vector = new T[size];
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &A)
{
	size = A.size;
	FirstInd=A.FirstInd;
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
TVector<T> TVector<T>::operator+(TVector<T> &A)
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
TVector<T> TVector<T>::operator-(TVector<T> &A)
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
		throw -1;
	return S;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(TVector<T> &A)
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
TVector<T> TVector<T>::operator*(T a)
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
TVector<T> TVector<T>::operator+(T a)
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
TVector<T> TVector<T>::operator-(T a)
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
TVector<T>& TVector<T>::operator=(TVector<T> &A)
{
	if (this != &A)
	{
		size = A.size;
		FirstInd=A.FirstInd;
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
		throw -1;
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator==(TVector<T> &A)
{
	int res=0;
	if( size == A.size)
	{
		for(int i = 0;i < size;i++)
		{
			if(vector[i] == A.vector[i])
				res=1;
		}
	}
	else return res;
	return res;
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>:: operator!=(TVector<T> &A)
{
	
	return !(*this==A);
}

template <class T>

class TMatrix : public TVector <TVector<T> >
{
public:
	TMatrix(int _n = 3);
	TMatrix(TMatrix &A);
	TMatrix(TVector<TVector<T> > &A);
	bool operator==(TMatrix &A);// сравнение
    TMatrix& operator= (TMatrix &A);// присваивание
    TMatrix operator+ (TMatrix &A);// сложение
    TMatrix operator- (TMatrix &A);// вычитание
    TMatrix operator* (TMatrix &A);// умножение
	
	//ввод/вывод в поток

	friend istream &operator>>(istream& A, TMatrix& B)
	{
		for (int i = 0; i < B.size; i++)
			A >> B.vector[i];
		return A;
	}
	friend ostream &operator<<(ostream& A, TMatrix& B)
	{
		for( int j=0;j<B.size;j++)
		{
			A << B.vector[j]<<"\n";
		}
		return A;
	}
};
//............................................................
template <class T> 
TMatrix<T>::TMatrix(int _n): TVector<TVector<T> >(_n)
{
    for(int i=0; i < _n; i++)
        this->vector[i]= TVector<T>(_n,i);
}




