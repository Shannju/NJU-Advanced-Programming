#define DEBUG
/*
 */
#include <iostream>
#include "stdio.h"
#include <fstream>
using namespace std;
int main()
{
  fstream ofs;
  ofs.open("./1.txt", ios::out);
  ofs.close();
  system("pause");
  return 0;
}
