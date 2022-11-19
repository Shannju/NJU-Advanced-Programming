#include "structure.h"
#include "file.h"

Item::Item(const Item &i)
{
  id = i.id;
  name = i.name;
  state = i.state;
};

void User::show()
{
  cout << id << "\t" << name << "\t" << password << "\t" << phoneNumber << "\t" << address << "\t" << balance << "\t" << state << endl;
}
User::User(string i, string n, string p, string c, string ad) : Item(i, n, 1), password(p), phoneNumber(c), address(ad)
{
  balance = 0;
}

Goods::Goods(string i, string n, double p, int num, string d, string sid) : Item(i, n, 1)
{
  price = p;    //大于零的小数，精确到小数点后一位
  number = num; // n>0为数量
  description = d;
  sellerID = sid;
  addedDate = getTime(); // yyyy-mm-dd
  t = getTime_value();
}
void Goods::show()
{
  cout << id << "\t" << name << "\t" << price << "\t" << number << "\t" << sellerID << "\t" << addedDate << "\t" << state << endl;
  cout << "描述"
       << "\t" << description << endl;
}
void Goods::check(file<User> *u, file<Order> *o) //对于这个商品的拍卖list
{
  vector<Auction_item> ans;
  if (state && getTime_value() >= t + 60) //拍卖时间到
  {
    sort(v.begin(), v.end()); //排序
    int i = 0;
    for (; i < v.size() && i < number; i++)
    {
      ans.push_back(v[i]);
      number -= 1;
    }
    v.clear();
    state = 0;
  }
  if (!v.empty()) //筛选出来的表不为空
  {
    cout << "提示：商品 " << id << "拍卖已结束" << endl;
    system("read -p '按任意键继续...' var");
;
    User *tmp_seller = u->search(sellerID);
    for (int j = 0; j < min((unsigned int)number, v.size()); j++)
    {
      User *tmp = u->search(v[j].getUid());
      double final_price = v[j].getOffer();
      if (tmp->getBalance() > final_price)
      {
        tmp->addBalance(-final_price);
        tmp_seller->addBalance(final_price);
        string d = getTime();
        string id_new = new_id();
        id_new.insert(0, "T");
        Order oitem(id_new, id, price, 1, d, tmp_seller->getID(), tmp->getID()); //构造订单
        o->add(oitem);
      }
    }
  }
}

void Order::show()
{
  cout << id << "\t" << commodityID << "\t" << unitPrice << "\t" << number << "\t" << date << "\t" << sellerID << "\t" << buyerID << endl;
}

void Goods ::auction(file<User> *u, int n, double offer, time_t time, string id)
{
  Auction_item a(n, offer, time, id);
  v.push_back(a);
}