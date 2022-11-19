#ifndef STRUC_H
#define STRUC_H
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "rand.h"
#include <algorithm>
#include "myVector.h"

using namespace std;

template <class T>
class file;

class Auction_item
{
private:
  int number;
  double offer;
  time_t time;
  string uid;

public:
  Auction_item(){};
  Auction_item(int n, double o, time_t t, string id) : number(n), offer(o), time(t), uid(id){};
  ~Auction_item(){};
  double getOffer() { return offer; };
  string getUid() { return uid; };
  bool operator<(const Auction_item &x)
  {
    if (x.offer > this->offer)
      return true;
    else if (x.offer == this->offer)
      return x.time < time;
    return false;
  }
};

class Item
{
protected:
  string id;
  string name;
  bool state;

public:
  Item(string i, string n, bool s) : id(i), name(n), state(s){};
  Item(){};
  Item(const Item &i);
  ~Item(){};
  string getID() { return id; };
  bool getState() { return state; };
  string getName() { return name; };
  void setName(string p) { name = p; };
  void setState(bool s) { state = s; };
  virtual void show() = 0;
};

class User : public Item
{
private:
  string password;
  string phoneNumber;
  string address;
  double balance;

public:
  User(){};
  ~User(){};
  User(string i, string n, string p, string c, string ad);
  void show();
  string getPass() { return password; };
  void setPass(string p) { password = p; };
  void showBalance() { cout << "���" << balance << "" << endl; };
  double getBalance() { return balance; };
  void addBalance(double m) { balance += m; };
  void addBalance(int m) { balance += m; };
  string getContact() { return phoneNumber; };
  string getAddress() { return address; };
  void setAddress(string p) { address = p; };
  void setContact(string p) { phoneNumber = p; };
};

class Order
{
private:
  string id;
  string commodityID;
  double unitPrice;
  int number;
  string date;
  string sellerID;
  string buyerID;

public:
  Order(/* args */){};
  Order(string i, string cid, double p, int n, string d, string sid, string bid) : id(i), commodityID(cid), unitPrice(p), number(n), date(d), sellerID(sid), buyerID(bid){};
  ~Order(){};
  void show();
  string getSID() { return sellerID; };
  string getBID() { return buyerID; };
};

class Goods : public Item
{
private:
  myVector<Auction_item> v;

private:
  time_t t;
  double price;
  int number;
  string description;
  string sellerID;
  string addedDate;

public:
  Goods(){};
  Goods(string i, string n, double p, int num, string d, string sid);
  ~Goods(){};
  int getNum() { return number; };
  string getSID() { return sellerID; };
  void setSID(string p) { sellerID = p; };
  void show();
  void kill() { state = 0; };
  int getPrice() { return price; };
  void setPrice(int p) { price = p; };
  string getDis() { return description; };
  void setDis(string p) { description = p; };
  void auction(file<User> *u, int n, double offer, time_t time, string id);
  void check(file<User> *u, file<Order> *o);
};

#endif
