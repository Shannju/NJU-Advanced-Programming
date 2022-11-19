#ifndef MY_VECTOR_H
#define MY_VECTOE_H
#pragma once
#include <cassert>
using namespace std;
//采用类模板实现的。
template <class T>
class myVector
{
public:
  typedef T *iterator;
  myVector();
  myVector(int size, T const &a); //按照数量生成
  myVector(const myVector<T> &a); //拷贝构造
  ~myVector();
  //常量
  unsigned int size();
  unsigned int capacity();
  unsigned int max_capacity();
  //尾部操作
  void push_back(const T &val);
  void pop_back();
  //重载操作符
  T &operator[](int index);
  myVector<T> &operator=(const myVector<T> &a);

  bool empty() const;
  //迭代器
  iterator begin() const;
  iterator end() const;

private:
  unsigned int _size;
  unsigned int _capacity;
  T *_buf;
  const unsigned int _max_ = 65536;
};

template <class T>
myVector<T>::myVector()
{
    _size = 0;
    _buf = new T[1];
    _capacity = 1;
}

template <class T>
myVector<T>::myVector(int s, const T &a)
{
    if (s > _max_)
        s = _max_;
    _size = s;
    _capacity = 1;
    while (_capacity < _size)
        _capacity *= 2;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++)
        _buf[i] = a;
}

template <class T>
myVector<T>::myVector(const myVector<T> &a)
{
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++)
        _buf[i] = a._buf[i];
}

template <class T>
myVector<T>::~myVector()
{
    delete[] _buf;
}

template <class T>
unsigned int myVector<T>::size()
{
    return _size;
}

template <class T>
unsigned int myVector<T>::capacity()
{
    return _capacity;
}
template <class T>
unsigned int myVector<T>::max_capacity()
{
    return _max_;
}

template <class T>
T &myVector<T>::operator[](int index)
{
    assert(index >= 0 && index < _size);
    return _buf[index];
}

template <class T>
void myVector<T>::push_back(const T &val)
{
    if (_size < _capacity)
    {
        _buf[_size] = val;
        _size++;
        return;
    }
    else if (_size == _max_)
    {
        return;
    }
    else
        {
            _capacity *= 2;
            if (_capacity >= _max_)
                _capacity = _max_;
            T *tmp = new T[_capacity];
            for (int i = 0; i < _size; i++)
                tmp[i] = _buf[i];
            tmp[_size] = val;
            _size++;
            delete[] _buf;
            _buf = tmp;
        }
}

template <class T>
void myVector<T>::pop_back()
{
    assert(_size > 0);
    _size--;
}

template <class T>
bool myVector<T>::empty() const
{
    if (_size == 0)
    {
        return true;
    }
    return false;
}

// 迭代器的实现
template <class T>
typename myVector<T>::iterator myVector<T>::begin() const
{
    return _buf;
}

template <class T>
typename myVector<T>::iterator myVector<T>::end() const
{
    return _buf + _size;
}

template <class T>
myVector<T> &myVector<T>::operator=(const myVector<T> &a)
{
    if (this == &a)
    {
        return *this;
    }
    delete[] _buf;
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++)
        _buf[i] = a._buf[i];
    return *this;
}


#endif
