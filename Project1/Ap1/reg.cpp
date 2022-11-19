#include "reg.h"

int reg_inum()
{
  string s;
  cin >> s;
  int price;
  regex p0("[0-9]*");
  price = atof(s.c_str());
  while ((!regex_match(s, p0)) || (price <= 0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
    price = atof(s.c_str());
  }
  return price;
}

double reg_dnum()
{
  string s;
  cin >> s;
  regex p0("[1-9]\\d*\\.?\\d*");
  double price = atof(s.c_str());
  while ((!regex_match(s, p0)) || (price <= 0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
    price = atof(s.c_str());
  }
  return price;
}

string reg_name()
{
  string s;
  cin >> s;
  regex name0("^[a-zA-Z]{1,10}$");
  while (!regex_match(s, name0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
  }
  return s;
}

string reg_password()
{
  string s;
  cin >> s;
  regex pw0("^[a-z0-9]{1,20}$");
  while (!regex_match(s, pw0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
  }
  return s;
}

string reg_con()
{
  string s;
  cin >> s;
  regex pw0("^[0-9]{1,20}$");
  while (!regex_match(s, pw0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
  }
  return s;
}
string reg_add()
{
  string s;
  cin >> s;
  regex pw0("^[a-zA-Z]{1,40}$");
  while (!regex_match(s, pw0))
  {
    cout << "输入不符合要求 请重新输入" << endl;
    cin >> s;
  }
  return s;
}