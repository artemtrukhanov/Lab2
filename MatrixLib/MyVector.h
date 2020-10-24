#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 10000;

template <class T>
class Vector
{
protected:
  int length;
  T* x;
public:
  Vector<T>* vec;
  Vector();
  Vector(int _v);
  Vector(int rowsCount, T* _v);
  Vector(int rowsCount, T _v);
  Vector(const Vector<T>& _v);
  virtual ~Vector();

  Vector operator +(const T& _v);
  Vector operator -(const T& _v);
  Vector operator *(const T& _v);
  Vector operator /(const T& _v);
  Vector<T>& operator =(const Vector<T>& _v);
  T& operator[] (const int index);
  bool operator ==(const Vector<T>& _v) const;
  bool operator !=(const Vector<T>& _v) const;

  Vector operator +(const Vector& _v);
  Vector operator -(const Vector& _v);
  Vector operator *(const Vector& _v);

  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vector<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vector<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    ostr << A.x[i] << '\t'; 
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
  length = 0;
  x = 0;
}

template <class T>
Vector<T>::Vector(int _v)
{
    if (_v < 0||_v > MAX_VECTOR_SIZE)
        throw new exception();
    length = _v;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = _v;
}

template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
  length = rowsCount;

  ///x = _v;

  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v[i];
}

template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
    if (_v < 0)
        throw new exception;

    length = rowsCount;
    x = new T [length];
    for (int i = 0; i < length; i++)
     x[i] = _v;
}

template <class T>
Vector<T>::Vector(const Vector<T>& _v)
{
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}

template <class T>
Vector<T>::~Vector()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}

template<class T>
bool Vector<T>::operator ==(const Vector<T>& _v) const
{
    for (int i = 0; i < length; i++)
        if (x[i] != _v.x[i])
            return false;
    return true;
}

template<class T>
bool Vector<T>::operator !=(const Vector<T>& _v) const
{
    for (int i = 0; i < length; i++)
        if (x[i] == _v.x[i])
            return false;
    return true;
}

template <class T>
Vector<T> Vector<T>::operator +(const T& _v)
{
  Vector<T> res;
  res.length = length;
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v;
  }
  return res;
}

template <class T>
Vector<T> Vector<T>::operator -(const T& _v)
{
  Vector<T> res;
  res.length = length;
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v;
  }
  return res;
}

template <class T>
Vector<T> Vector<T>::operator *(const T& _v)
{
  Vector<T> res;
  res.length = length;
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] * _v;
  }
  return res;
}

template <class T>
Vector<T> Vector<T>::operator /(const T& _v)

{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}

template <class T>
T& Vector<T>::operator[] (const int index)
{
    if (index<0 || index>length)
        throw "Error";
    if ((index >= 0) && (index < length))
        return x[index];
    return x[0];
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector& _v)
{
    if (_v.length != length)
        throw new exception;

    Vector<T> res;
    res.length = length;
    res.x = new T[res.length];
    for (int i = 0; i < res.length; i++)
        res.x[i] = x[i] + _v.x[i];
    return res;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector& _v)
{
    if (_v.length != length)
        throw new exception;

    Vector<T> res;
    res.length = length;
    res.x = new T[res.length];
    for (int i = 0; i < res.length; i++)
        res.x[i] = x[i] - _v.x[i];
    return res;
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector& _v)
{
    if (_v.length != length)
        throw new exception;

    Vector<T> res;
    res.length = length;
    res.x = new T[res.length];
    for (int i = 0; i < res.length; i++)
        res.x[i] = x[i] * _v.x[i];
    return res;
}


template <class T>
int Vector<T>::Length()
{
  return length;
}

#endif