#ifndef FILE_H
#define FILE_H
#pragma once
#include "structure.h"
#include <cstring>
#include <fstream>
#include <iostream>

class Goods;
class User;
class Order;

template <class T>
class file
{

private:
public:
  myVector<T> ls;
  void open();
  void load();
  int del(string id);
  void add(T u);
  T *search(string id);
  T *search_name(string name);
  myVector<T *> fuzzy(string name);
  myVector<T *> search_id_seller(string id);
  myVector<T *> search_id_buyer(string id);
  void save();
  void show();
  void show_col();
  int getSize() { return ls.size(); };
  void check(file<User> *u, file<Order> *o);
  file(string name);
  file();
  ~file();

private:
  string name;
  string file_name;
  unsigned int _size;
};
template <class T>
void file<T>::check(file<User> *u, file<Order> *o)
{
  if (is_same<T, Goods>::value)
  {
    for (int i = 0; i < ls.size(); i++) //遍历商品表格
    {
      // myVector<Auction_item> v;
      Goods *tmp_goods = &(ls[i]);
      tmp_goods->check(u, o); //每个商品的check
    }
  }
}

template <class T>
void file<T>::show_col()
{
  if (is_same<T, Goods>::value)
  {
    cout << "商品ID"
         << "\t"
         << "名称"
         << "\t"
         << "价格"
         << "\t"
         << "数量"
         << "\t"
         << "卖家ID"
         << "\t"
         << "上架时间"
         << "\t"
         << "商品状态" << endl;
    return;
  }
  else if (is_same<T, Order>::value)
  {
    cout << "订单ID"
         << "\t"
         << "商品ID"
         << "\t"
         << "单价"
         << "\t"
         << "数量"
         << "\t"
         << "交易时间"
         << "\t"
         << "卖家ID"
         << "\t"
         << "买家ID" << endl;
    return;
  }
  else if (is_same<T, User>::value)
  {
    cout << "ID"
         << "\t"
         << "名称"
         << "\t"
         << "密码"
         << "\t"
         << "联系方式"
         << "\t"
         << "地址"
         << "\t"
         << "余额"
         << "\t"
         << "用户状态" << endl;
    return;
  }
  else
    return;
};
template <class T>
file<T>::file()
{
  this->name = "";
  this->file_name = ".txt";
  this->_size = sizeof(T);
  this->ls = myVector<T>();
}

template <class T>
file<T>::file(string name)
{
  this->name = name;
  this->file_name = name + ".txt";
  this->_size = sizeof(T);
  this->ls = myVector<T>();
}

template <class T>
file<T>::~file()
{
}

template <class T>
void file<T>::open()
{
  ifstream ifs;
  ifs.open(file_name, ios::in);

  if (!ifs.is_open()) //?????????
  {
    // cout << file_name << "????????? ??????????" << endl;
    fstream out_file;
    out_file.open(file_name, ios::out | ios::binary);
    return;
  }
  char ch;
  ifs >> ch;
  if (ifs.eof())
  {
    // cout << file_name << "??????" << endl;
    ifs.close();
    return;
  }
  this->load();
}
template <class T>
void file<T>::add(T u)
{
  ls.push_back(u);
}

template <class T>
void file<T>::load() //????? ????myVector????
{
  ifstream ifs;
  ifs.open(file_name, ios::in | ios::binary);

  while (true)
  {
    T *tmp = new T();
    ifs.read((char *)(tmp), _size);
    if (ifs.eof())
      break;
    this->add(*tmp);
  }

  ifs.close();
}

template <class T>
void file<T>::save()
{
  fstream fs;
  fs.open(file_name, ios::out | ios::binary);
  for (int i = 0; i < ls.size(); i++)
    fs.write((char *)(&ls[i]), _size);
  fs.close();
}

template <class T>
void file<T>::show()
{
  if (this->ls.empty())
    cout << "列表为空" << endl;
  else
  {

    for (int i = 0; i < ls.size(); i++)
      ls[i].show();
  }
}

template <class T>
T *file<T>::search(string id)
{
  if (this->ls.empty())
    return NULL;
  int len = this->ls.size();
  T *u = &this->ls[0];
  for (int i = 0; i < len; u++, i++)
  {
    if (strcmp(u->getID().c_str(), id.c_str()) == 0)
      return u;
  }
  return NULL;
}

template <class T>
T *file<T>::search_name(string name)
{
  if (this->ls.empty())
    return NULL;
  int len = this->ls.size();
  T *u = &this->ls[0];
  for (int i = 0; i < len; u++, i++)
  {
    if (strcmp(u->getName().c_str(), name.c_str()) == 0)
      return u;
  }
  return NULL;
}
template <class T>
myVector<T *> file<T>::fuzzy(string name)
{
  myVector<T *> v;
  if (this->ls.empty())
    return v;
  int len = this->ls.size();
  T *u = &this->ls[0];
  for (int i = 0; i < len; u++, i++)
  {
    if (u->getName().find(name) != name.npos)
      v.push_back(u);
  }
  return v;
}
template <class T>
int file<T>::del(string id)
{
  T *temp = search(id);

  while (!temp) //??????
    return 0;
  if (temp->getState() == 0) //??????
    return 1;
  temp->setState(0);
  return 2;
}

template <class T>
myVector<T *> file<T>::search_id_seller(string id)
{
  myVector<T *> v;
  if (is_same<T, Goods>::value || is_same<T, Order>::value)
  {
    myVector<T *> v;
    if (this->ls.empty())
      return v;
    int len = this->ls.size();
    T *u = &this->ls[0];
    for (int i = 0; i < len; u++, i++)
    {
      if (strcmp(u->getSID().c_str(), id.c_str()) == 0)
        v.push_back(u);
    }
    return v;
  }
  else
    return v;
}
template <class T>
myVector<T *> file<T>::search_id_buyer(string id)
{
  myVector<T *> v;
  if (is_same<T, Order>::value)
  {

    if (this->ls.empty())
      return v;
    int len = this->ls.size();
    T *u = &this->ls[0];
    for (int i = 0; i < len; u++, i++)
    {
      if (strcmp(u->getBID().c_str(), id.c_str()) == 0)
        v.push_back(u);
    }
    return v;
  }
  else
    return v;
}

#endif