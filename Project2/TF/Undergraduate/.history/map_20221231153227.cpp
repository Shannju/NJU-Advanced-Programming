#include "map.h"

Map::Map():heng(15),shu(7)
{

}

int *Matrix::operator[](int i)
{
    return a[i];
}
int Matrix::operator()(int i, int j)
{
    return a[i][j];
}
Matrix::Matrix(int x, int y)
{
    colunm = x;
    row = y;
    a = new int *[x];
    for (int i = 0; i < x; ++i)
        a[i] = new int[y];
}

Matrix::~Matrix()
{
    for (int i = 0; i < colunm; ++i)
        delete[] a[i];
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

void Map::read_file()
{
    ifstream ifs;
  ifs.open(MAP_File, ios::in);
    if (!ifs.is_open())
    {
        debug(file map.txt dont exist, new one created. )
        fstream out_file;
        out_file.open(MAP_File, ios::out);
        return;
    }
    for (int i=0;i<shu,i++)
        for (int j=0;i<heng,j++)
        {
            
        }

}
