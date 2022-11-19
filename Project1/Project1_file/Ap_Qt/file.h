#ifndef FILE_H
#define FILE_H
#pragma once
#define DEBUG
#include <cstring>
#include <fstream>
#include <iostream>
#include "myVector.h"
// #include <QStandardItemModel>
using namespace std;

template <class T>
class file
{
private:
  myVector<T> ls;

public:
  void open();
  void load();
  void del(string id);
  void add(T u);
  void save();
  //  void show();
  file(string name);
  // virtual QStandardItemModel v2m();
  ~file();

private:
  string name;
  string file_name;
  unsigned int _size;
};

template <class T>
file<T>::file(string name)
{
  this->name = name;
  this->file_name = name + ".txt";
  this->_size = sizeof(T);
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

  if (!ifs.is_open()) //文件不存在
  {
    cout << file_name << "文件不存在 已创建新文件" << endl;
    fstream out_file;
    out_file.open(file_name, ios::out | ios::binary);
    return;
  }
  char ch;
  ifs >> ch;
  if (ifs.eof())
  {
    cout << file_name << "文件为空" << endl;
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
void file<T>::load() //初始化 读到vector里面
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
#ifdef DEBUG
    cout << "n: " << tmp->id << endl;
#endif
  }

  ifs.close();
}

template <class T>
void file<T>::save()
{
  fstream fs;
  fs.open(file_name, ios::out | ios::binary);
  // for (vector<User>::iterator ite = this->ls.begin(); ite != this->ls.end(); ite++)
  //   ofs << ite->id << " " << ite->name << " " << ite->password << " " << ite->contact << " " << ite->address << " " << ite->money << " " << ite->killed << " ";
  for (int i = 0; i < ls.size(); i++)
    fs.write((char *)(&ls[i]), _size);
  fs.close();
}
// template <class T>
// QStandardItemModel file<T>::v2m(int tsize)
// {
//   QStandardItemModel m;
//   m.rowCount() = ls.size();

//   for (int i = 0; i < ls.size(); i++)
//   {
//     m.setHeaderData(i, Qt::Vertical, ls[i].name);
//     for (int j = 0; j < tsize; j++)
//             m.setItem(i,j,new QStandardItem(ls[i]) );
//   }
// }

#endif
