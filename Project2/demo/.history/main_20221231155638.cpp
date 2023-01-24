#define DEBUG
/*
 */
#include <iostream>
#include "stdio.h"
#include <fstream>
using namespace std;
int main()
{
  ofstream ofs;
  ofs.open("D:/Data/Advanced Programming/NJU-Advanced-Programming/Project2/demo/1.txt", ios::out);
  ofs.close();
  system("pause");
  return 0;
}
