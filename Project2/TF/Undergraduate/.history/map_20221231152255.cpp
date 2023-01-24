#include "map.h"

Map::Map()
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

    try
    {
        ifs.open(MAP_File, ios::in);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    if (!ifs.is_open())
    {
        // cout << file_name << "????????? ??????????" << endl;
        fstream out_file;
        out_file.open(file_name, ios::out | ios::binary);
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.peek() == EOF)
    {
        // cout << file_name << " empty" << endl;
        system("read -p 'debuging...' var");
        ifs.close();
        return;
    }
}
