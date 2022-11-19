#pragma once
#include "file.h"
#include "rand.h"
#include "reg.h"

class menu
{
protected:
	bool stop;

public:
	virtual void show_menu() = 0;
	virtual void func_menu() = 0;
	virtual void exit_menu() = 0;
	menu() { stop = 0; };
	bool getStop() { return stop; };
};

class RealMenu : public menu
{
protected:
	file<Order> *o;
	file<User> *u;
	file<Goods> *g;

public:
	// file<cGoods> *cg;
	void search_menu();
	void check();
	RealMenu(file<User> *u, file<Goods> *g, file<Order> *o);
	RealMenu(){};
	~RealMenu(){};
	// void save_goods();
	// void load_goods();
};

class MainMenu : public RealMenu
{
public:
	void show_menu();
	void func_menu();
	void exit_menu();
	void halt();
	void Sign_in();
	void Sign_in_admin();
	void Sign_up();

	MainMenu(file<User> *u, file<Goods> *g, file<Order> *o) : RealMenu(u, g, o){};
	MainMenu(){};
	~MainMenu(){};
};

class UserMenu : public RealMenu
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
	// UserMenu(const UserMenu& um){};
	UserMenu(file<User> *u, file<Goods> *g, file<Order> *o, User *m) : RealMenu(u, g, o) { me = m; };

	~UserMenu(){};

protected:
	User *me;
};

class BuyerMenu : public UserMenu
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

class adminMenu : public RealMenu
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
