#pragma once
#include "file.h"
#include "rand.h"
#include "reg.h"

class menu // 抽象菜单类
{
protected:
	bool stop;

public:
	virtual void show_menu() = 0; //打印信息
	virtual void func_menu() = 0; //切换选项，功能跳转
	virtual void exit_menu() = 0; //退出循环并且打印提示
	menu() { stop = 0; };
	bool getStop() { return stop; };
};

class RealMenu : public menu //菜单实例 增加了三个文件指针
{
protected:
	file<Order> *o;
	file<User> *u;
	file<Goods> *g;

public:
	void search_menu();
	void check(); //拍卖函数
	RealMenu(file<User> *u, file<Goods> *g, file<Order> *o);
	RealMenu(){};
	~RealMenu(){};
};

class MainMenu : public RealMenu //主菜单
{
public:
	//虚函数
	void show_menu();
	void func_menu();
	void exit_menu();
	void halt();
	//功能函数
	void Sign_in();
	void Sign_in_admin();
	void Sign_up();

	MainMenu(file<User> *u, file<Goods> *g, file<Order> *o) : RealMenu(u, g, o){};
	MainMenu(){};
	~MainMenu(){};
};

class UserMenu : public RealMenu//用户界面
{
public:
	void show_menu();
	void func_menu();
	void exit_menu();

	void halt();
	void inf();
	void inf_func();
	void change_show();
	void change_func();

	void add_money();
	UserMenu(){};
	UserMenu(file<User> *u, file<Goods> *g, file<Order> *o, User *m) : RealMenu(u, g, o) { me = m; };

	~UserMenu(){};

protected://用户指针
	User *me;
};

class BuyerMenu : public UserMenu
//买家界面，继承自用户界面
{
public:
	void show_menu();
	void func_menu();
	void exit_menu();
	void change_func();
	void change_show();
	void show_order();
	void halt();
	void auction();
	BuyerMenu(){};
	BuyerMenu(const UserMenu &um) : UserMenu(um){};

	~BuyerMenu(){};
};

class SellerMenu : public UserMenu
//卖家界面，继承自用户界面
{
public:
	void show_menu();
	void func_menu();
	void exit_menu();
	void halt();
	void add_goods();
	void show_my_goods();
	void change_func();
	void change_show();
	void show_order();
	void off_shelf();

	SellerMenu(){};
	SellerMenu(const UserMenu &um) : UserMenu(um){};

	~SellerMenu(){};
};

class adminMenu : public RealMenu//管理界面
{
public:
	void show_menu();
	void func_menu();
	void exit_menu();
	void del_user();
	void off_shelf();
	void halt();

	adminMenu(file<User> *u, file<Goods> *g, file<Order> *o) : RealMenu(u, g, o){};
	adminMenu(){};
	~adminMenu(){};
};
