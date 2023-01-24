#ifndef MAP_H
#define MAP_H

#include <Marcos.h>
#include<fstream>
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

class Map
{
private:
    Matrix m;
    const int heng, shu;

public:
    Map();
    void read_file();
};

#endif // MAP_H
