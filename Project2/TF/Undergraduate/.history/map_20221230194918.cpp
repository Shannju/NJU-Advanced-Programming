#include "map.h"

Map::Map()
{

}

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