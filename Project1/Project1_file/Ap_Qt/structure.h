#ifndef STRUC_H
#define STRUC_H
#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;

// class item
// {
// private:
//   string id;
//   string name;

// public:
//   item(/* args */);
//   item(string id, string name);
//   ~item();
// };

// item::item(/* args */)
// {
// }

// item::item(string id, string name)
// {
//   this->id = id;
//   this->name = name;
// }

// item::~item()
// {
// }
struct User
{
  // userID 4个字符，开头字符为大写字母U，后3位为数字
  // username 不超过10个字符，英文字母

  string id;
  string name;
  // password 不超过20个字符，只由小写字母和数字组成
  // phoneNumber 不超过20个字符，由数字组成
  // address 不超过40个字符，英文字母
  // balance 保留一位小数
  // userState 包括active, inactive

  string password;
  string phoneNumber; //联系方式
  string address;     //地址
  double balance;     //余额
  bool userState;
};

struct Goods
{
  // commodityID 4个字符，开头字符为大写字母M，后3位为数字
  // commodityName 不超过20个字符，英文字母

  string id;
  string name;
  double price; //大于零的小数，精确到小数点后一位
  int number;   // n>0为数量
  string description;
  string sellerID;
  string addedDate; // yyyy-mm-dd
  bool state;       //包括removed, onAuction
};

struct Order
{
  string id;          //订单id
  string commodityID; //商品id
  string unitPrice;
  int number;
  string date;
  string sellerID;
  string buyerID;
};
#endif
