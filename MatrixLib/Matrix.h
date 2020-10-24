#pragma once

#include "MyVector.h"

const int MAX_SIZE = 10000;

template <class T>
class TMatrix : public Vector<Vector<T>>
{
public:
	TMatrix(int _size);
	TMatrix(const TMatrix<T>& A);
	~TMatrix();

	TMatrix<T>& operator = (const TMatrix<T>& A);
	TMatrix<T> operator + (const TMatrix<T>& A);
	TMatrix<T> operator - (const TMatrix<T>& A);
	TMatrix<T> operator*(TMatrix<T>& A);

	bool operator == (const TMatrix<T>& A) const;
	bool operator != (const TMatrix<T>& A) const;

	friend ostream& operator<< (ostream& ostr, const TMatrix& A)
	{
		for (int i = 0; i < A.length; i++)
			ostr << A.x[i] << endl;
		return ostr;
	}

	friend istream& operator>> (istream& istr, TMatrix& A)
	{
		for (int i = 0; i < A.Length; i++)
			istr >> A.x[i];
		return istr;
	}

};

template<class T>
inline TMatrix<T>::TMatrix(int _size) : Vector<Vector<T> >(_size)
{
	if (_size < 0 || _size > MAX_SIZE)
		throw  new exception;
	
	for (int i = 0; i < _size; i++)
		this->x[i] = Vector<T>(_size);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& A) : Vector<Vector<T> >(A)
{
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& A)
{
	if (this != &A)
	{
		if (this->length != A.length)
		{
			delete[] this->x;
			this->length = A.length;
			this->x = new Vector<T>[A.length];
			for (int i = 0; i < A.length; i++)
				this->x[i] = A.x[i];
		}
	
		for (int i = 0; i < this->length; ++i)
			this->x[i] = A.x[i];
	}
	return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& A)
{
	if (this->length != A.length)
		throw "Error";

	TMatrix<T> tmp(*this);
	for (int i = 0; i < this->length; i++)
		tmp.x[i] = tmp.x[i] + A.x[i];

	return 	tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A)
{
	TMatrix<T> tmp(*this);
	if (this->length != A.length)
		throw new exception;
	for (int i = 0; i < this->length; i++)
		tmp.x[i] = tmp.x[i] - A.x[i];

	return 	tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(TMatrix<T>& A)
{
	TMatrix<T> tmp(*this);
	if (this->length != A.length)
		throw new exception;
	for (int i = 0; i < this->Length(); i++)
		tmp.x[i] = tmp.x[i] * A.x[i];
	return tmp;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T> &A) const
{
	for (int i = 0; i < A.length; i++)
		if (this->x[i] != A.x[i])
			return false;
	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T> &A) const
{
	for (int i = 0; i < A.length; i++)
		if (this->x[i] == A.x[i])
			return false;
	return true;
}
