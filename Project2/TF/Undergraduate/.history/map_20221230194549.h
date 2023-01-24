#ifndef MAP_H
#define MAP_H


#include <iostream>
using namespace std;
class Matrix
{
public:
  int colunm;
  int row;
  int **a;
  Matrix();
  Matrix(int x, int y)
  {
    colunm = x;
    row = y;
    a = new int *[x];
    for (int i = 0; i < x; ++i)
      a[i] = new int[y];
  }
  ~Matrix()
  {
    for (int i = 0; i < colunm; ++i)
      delete[] a[i];
  }
  Matrix operator=(Matrix B);
  int *operator[](int i);
  int operator()(int i, int j);
};
int *Matrix::operator[](int i)
{
  return a[i];
}
int Matrix:: operator()(int i, int j)
{
  return a[i][j];
}
Matrix Matrix::operator=(Matrix B)
{
  if (!(colunm == B.colunm && row == B.row))
  {
    cout << "false";
    return *this;
  }
  else
  {
    Matrix C;
    int **b;
    b = new int *[colunm];
    for (int i = 0; i < colunm; ++i)
      b[i] = new int[row];
    C.a = b;
    for (int i = 0; i < colunm; ++i)
      for (int j = 0; j < row; ++j)
        C.a[i][j] = a[i][j];
    return C;
  }
}

class Map
{
private:
    int*
public:
    Map();

};

#endif // MAP_H
