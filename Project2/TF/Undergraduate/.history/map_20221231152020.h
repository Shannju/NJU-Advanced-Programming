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
    Matrix(){};
    Matrix(int x, int y);
    ~Matrix();
    Matrix operator=(Matrix B);
    int *operator[](int i);
    int operator()(int i, int j);
};

class Map
{
private:
    Matrix m;
//    const int heng, shu;

public:
    Map();
    void read_file();
};

#endif // MAP_H
