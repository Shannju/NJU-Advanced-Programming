#include "menu.h"

void MainMenu::halt()
{
    while (!getStop())
    {
        show_menu();
        check();
    }
}
void UserMenu::halt()
{
    while (!getStop())
    {
        show_menu();
        check();
    }
}
void SellerMenu::halt()
{
    while (!getStop())
    {
        show_menu();
        check();
    }
}
void BuyerMenu ::halt()
{
    while (!getStop())
    {
        show_menu();
        check();
    }
}

void adminMenu::halt()
{
    while (!getStop())
    {
        show_menu();
        check();
    }
}

RealMenu::RealMenu(file<User> *u, file<Goods> *g, file<Order> *o)
{
    this->u = u;
    this->g = g;
    this->o = o;
    stop = 0;
}

void adminMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             管理" << endl;
    cout << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 " << endl;
    cout << "6.封禁用户     7.注销" << endl;
    cout << "==================================================================" << endl;
    cout << "请选择一个操作" << endl;
    this->func_menu();
}

void adminMenu::func_menu()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {

    case (1):
    {
        g->show_col();
        this->g->show();
    }
    break;
    case (2):
    {
        search_menu();
    };
    break;
    case (3):
    {
        cout << "商品列表如下" << endl;
        this->g->show();
        off_shelf();

        break;
    }
    case (4):
    {
        o->show_col();
        this->o->show();
    }
    break;
    case (5):
    {
        u->show_col();
        this->u->show();
        break;
    }
    case (6):
    {
        del_user();
    };
    break;
    case (7):
    {
        exit_menu();
        return;
    }
    break;
    default:;
        {
            cout << "没有这个选项哦" << endl;
            cout << "再给你一次选择的机会" << endl;
        };
        break;
    }
    system("pause");
    return;
}

void adminMenu::del_user()
{
    cout << "==================================================================" << endl;
    cout << "                              封禁用户" << endl;
    cout << "请输入用户的姓名" << endl;
    string n;
    cin >> n;

    User *real = u->search_name(n);
    if (!real) //搜不到
    {
        cout << "用户不存在" << endl;
        system("pause");
        show_menu();
        return;
    }
    string id = real->getID();
    int ans = u->del(id);
    switch (ans)
    {
    case 0:
    {
        cout << "用户不存在" << endl;

        return;
    }
    break;
    case 1:
    {
        cout << "用户 " << id << " 已经封禁" << endl;

        return;
    }
    case 2:
    {
        myVector<Goods *> v = g->search_id_seller(id);
        for (int i = 0; i < v.size(); i++)
            v[i]->kill();
        cout << "已将用户 " << id << " 封禁" << endl;
    }

    default:
        break;
    }
}

void adminMenu::off_shelf()
{
    cout << "==================================================================" << endl;
    cout << "                             下架商品" << endl;
    cout << "请输入下架商品的id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);

    if (!temp) //包括removed 0, onAuction 1
    {
        cout << "商品不存在" << endl;

        return;
    }
    if (temp->getState() == 0)
    {
        cout << "商品 " << id << " 已经下架" << endl;

        return;
    }
    if (temp->getState() == 1)
    {
        temp->setState(0);
        cout << "商品 " << id << " 下架成功" << endl;

        return;
    }
}

void adminMenu::exit_menu() //注销
{
    stop = 1;
    cout << "已退出管理员系统" << endl;
    system("pause");
}

void RealMenu::check() //菜单里面运行check
{
    g->check(u, o);
}

void RealMenu::search_menu()
{
    cout << "请输入商品的名字" << endl;
    string name;
    cin >> name;
    myVector<Goods *> v = g->fuzzy(name);
    if (v.empty())
    {
        cout << "商品不存在" << endl;
        return;
    }
    g->show_col();
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->show();
    }
}
void UserMenu::exit_menu()
{
    system("cls");
    stop = 1;
    cout << "已退出买家系统" << endl;
    system("pause");
    // this->User_Menu_show();
}
void UserMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             用户菜单" << endl;
    cout << "          1.注销登录 2.我是买家 3.我是卖家 4.个人信息管理" << endl;
    cout << "==================================================================" << endl;
    cout << "请选择一个操作" << endl;
    func_menu();
}
void UserMenu::func_menu()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        exit_menu();
        return;
    }
    case (2):
    {
        BuyerMenu bm = BuyerMenu(*this);
        bm.halt();
        break;
    }

    case (3):
    {
        SellerMenu sm = SellerMenu(*this);
        sm.halt();
        break;
    }

    case (4):
    {
        inf();
        break;
    }

    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;

        break;
    };
    }

    return;
}

void UserMenu::inf()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             个人信息" << endl;
    cout << "              1.查看信息 2.修改信息 3.充值 4.返回用户界面" << endl;
    cout << "==================================================================" << endl;
    this->inf_func();
}
void UserMenu::inf_func()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        cout << "个人信息如下" << endl;
        u->show_col();
        me->show();
        system("pause");
    };
    break;
    case (2):
    {
        change_show();
    };
    break;
    case (3):
    {
        add_money();
    };
    break;
    case (4):
    {
        exit_menu();
        return;
    }
    break;
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
        inf();
    };
    }
    inf();
}

void UserMenu::add_money()
{
    cout << "==================================================================" << endl;
    cout << "                             充值" << endl;
    cout << "请输入密码" << endl;
    string pw;
    cin >> pw;
    int i = 0;
    for (; i < 5; i++)
    {
        if (me->getPass() != pw)
        {
            cout << "输入错误,请再次输入" << endl;
            cin >> pw;
        }
        else
            break;
    }
    if (i == 5)
    {
        cout << "输入错误已达5次，封禁该用户" << endl;
        u->del(me->getID());
        system("pause");
        return;
    }
    else
    {
        cout << "请输入金额" << endl;
        string ns;
        cin >> ns;
        int n = atof(ns.c_str());
        if (0 < n)
        {
            me->addBalance(n);
            cout << "成功充值" << n << "元" << endl;
            me->showBalance();
        }
        else
            cout << "充值失败" << endl;
    }
    system("pause");
}

void UserMenu::change_show()
{
    cout << "请输入密码" << endl;
    string pw;
    cin >> pw;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (me->getPass() != pw)
        {
            cout << "输入错误,请再次输入" << endl;
            cin >> pw;
        }
        else
            break;
    }
    if (i == 5)
    {
        cout << "输入错误已达5次，封禁该用户" << endl;
        u->del(me->getID());
        exit_menu();
        return;
    }

    cout << "==================================================================" << endl;
    cout << "                             修改信息" << endl;
    cout << "          1.修改姓名 2.修改密码 3.修改联系方式 4.修改地址" << endl;
    cout << "==================================================================" << endl;
    this->change_func();
}

void UserMenu::change_func()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        cout << "请输入名字" << endl;
        me->setName(reg_name());
    };
    break;
    case (2):
    {
        cout << "请输入密码 （不超过20个字符，只由小写字母和数字组成）" << endl;
        me->setPass(reg_password());
    };
    break;
    case (3):
    {

        cout << "请输入联系方式	(不超过20个字符，由数字组成)" << endl;
        me->setContact(reg_con());
    };
    break;
    case (4):
    {
        cout << "请输入地址	" << endl;
        me->setAddress(reg_add());
    }
    break;
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
        this->change_show();
    };
    }
    cout << "修改成功" << endl;
    cout << "即将返回上一级" << endl;
    system("pause");
}

void BuyerMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           买家菜单" << endl;
    cout << "1.查看商品列表 2.竞拍商品 3.搜索商品 4.查看历史订单（自己）" << endl;
    cout << "5.返回用户主界面 " << endl;
    cout << "==================================================================" << endl;
    this->func_menu();
}
void BuyerMenu::func_menu()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        g->show_col();
        g->show();
        break;
    }

    case (2):
    {
        auction();
        break;
    }

    case (3):
    {
        search_menu();
        break;
    };

    case (4):
    {
        show_order();
        break;
    }
    case (5):
    {
        exit_menu();
        return;
    }
    break;
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
    };
    break;
    }
    system("pause");
}

void BuyerMenu::auction()
{
    cout << "==================================================================" << endl;
    cout << "                         竞拍商品" << endl;
    cout << "商品列表如下" << endl;
    g->show();
    cout << "请输入竞拍商品的id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id); //找到商品为temp

    while (!temp)
    {
        cout << "商品不存在" << endl;
        system("pause");
        return;
    }
    User *seller = u->search(temp->getSID()); //找到卖家为seller

    if (temp->getState() == 0)
    {
        cout << "商品不可竞拍" << endl;
        system("pause");

        return;
    }

    if (temp->getNum() <= 0)
    {
        cout << "商品已经售空" << endl;
        system("pause");

        return;
    }

    if (temp->getSID() == me->getID())
    {
        cout << "不可竞拍自己的商品" << endl;
        system("pause");

        return;
    }
    int num;
    cout << "请输入竞拍数量" << endl;
    num = reg_inum();

    double offer;
    cout << "请输入竞拍价格" << endl;
    offer = reg_dnum();
    if (offer < temp->getPrice())
    {
        cout << "竞拍价格不得少于商品底价：" << temp->getPrice() << endl;
        system("pause");
        return;
    }
    if (offer * num > me->getBalance())
    {
        cout << "余额不足 请充值" << endl;
        system("pause");
        return;
    }
    time_t t = getTime_value();
    temp->auction(u, num, offer, t, me->getID());
    cout << "成功竞拍本商品" << endl;
}
void BuyerMenu::exit_menu()
{
    stop = 1;
    cout << "已退出买家系统" << endl;
    system("pause");
}

void SellerMenu ::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           卖家菜单" << endl;
    cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品" << endl;
    cout << "5.查看历史订单 6.返回用户界面" << endl;
    cout << "==================================================================" << endl;
    func_menu();
}
void SellerMenu ::func_menu()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {

    case (1):
        this->add_goods();
        break;
    case (2):
    {
        this->show_my_goods();
    }

    break;
    case (3):
    {
        cout << "您的商品列表如下" << endl;
        this->show_my_goods();
        change_show();
    }

    break;
    case (4):
        this->off_shelf();
        break;
    case (5):
        this->show_order();
        break;
    case (6):
    {
        this->exit_menu();
        return;
    }
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
    };
    break;
    }
    system("pause");
}
void SellerMenu ::exit_menu()
{
    stop = 1;
    system("cls");
    cout << "已退出卖家系统" << endl;
    system("pause");
}
void SellerMenu ::add_goods()
{
    cout << "==================================================================" << endl;
    cout << "                           发布商品" << endl;
    cout << "==================================================================" << endl;
    string id_new = new_id();
    id_new.insert(0, "M");

    string name;
    cout << "请输入商品名称" << endl;
    cin >> name;
    string s_price;
    cout << "请输入商品价格" << endl;
    double price = reg_dnum();
    cout << "请输入商品数量" << endl;
    int number = reg_inum();
    string dis;
    cout << "请输入描述" << endl;
    getchar();
    getline(cin, dis);
    if (regex_search(dis, regex("\\s")))
    {
        cout << "不得带有空格哦 请再次输入" << endl;
        cin >> dis;
    }
    Goods gitem(id_new, name, price, number, dis, me->getID()); //构造订单
    g->add(gitem);
}

void SellerMenu ::show_my_goods()
{
    cout << "==================================================================" << endl;

    myVector<Goods *> v = g->search_id_seller(me->getID());
    if (v.empty())
        cout << "你还没有上架商品" << endl;
    else
    {
        g->show_col();
        if (g->ls.empty())
            cout << "列表为空" << endl;
        else
        {
            for (int i = 0; i < g->ls.size(); i++)
            {
                if (g->ls[i].getSID() == me->getID())
                    g->ls[i].show();
            }
        }
    }
}
void SellerMenu ::change_show()
{
    cout << "==================================================================" << endl;
    cout << "                             修改商品" << endl;
    cout << "请输入修改商品的id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);
    while (!temp)
    {
        cout << "商品不存在" << endl;
        system("pause");

        return;
    }
    if (temp->getNum() <= 0)
    {
        cout << "商品已售空 不可修改" << endl;
        system("pause");

        return;
    }
    if (temp->getState() == 0)
    {
        cout << "商品已下架 不可修改" << endl;
        system("pause");

        return;
    }
    cout << "想要修改：1.名称 2.价格 3.描述" << endl;

    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        string new_name;
        cout << "请输入名字（不超过10个字符，英文字母）" << endl;
        cin >> new_name;
        regex name0("^[a-zA-Z]{1,10}$");
        while (!regex_match(new_name, name0))
        {
            cout << "输入有误 请再次输入" << endl;
            cin >> new_name;
        }
        temp->setName(new_name);
    };
    break;
    case (2):
    {
        string s_price;
        cout << "请输入价格(0-1w元)" << endl;
        cin >> s_price;
        regex p0("^[0-9]{1,5}$");
        int price = atof(s_price.c_str());
        while ((!regex_match(s_price, p0)) || (price <= 0))
        {
            cout << "输入有误 请再次输入" << endl;
            cin >> s_price;
            price = atof(s_price.c_str());
        }
        temp->setPrice(price);
    };
    break;
    case (3):
    {
        string dis;
        cout << "请输入描述" << endl;
        getchar();
        getline(cin, dis);
        temp->setDis(dis);
        break;
    }
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
        change_show();
        return;
    }
    break;
    }
    cout << "修改成功" << endl;
}

void SellerMenu ::off_shelf()
{
    cout << "==================================================================" << endl;
    cout << "                             下架商品" << endl;
    show_my_goods();
    cout << "请输入下架商品的id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);
    while (!temp)
    {
        cout << "商品不存在" << endl;
        system("pause");
        return;
    }

    if (temp->getState() == 0)
    {
        cout << "商品已下架" << endl;
        system("pause");

        return;
    }
    if (temp->getNum() <= 0)
    {
        cout << "商品已售空" << endl;
        system("pause");
        return;
    }
    if (strcmp(temp->getSID().c_str(), me->getID().c_str()) != 0)
    {
        cout << "您只能下架自己的商品" << endl;
        system("pause");
        return;
    }
    temp->setState(0);
    cout << "下架成功" << endl;
}

void BuyerMenu ::show_order()
{
    myVector<Order *> v = o->search_id_buyer(me->getID());
    if (v.empty())
        cout << "你还没有订单" << endl;
    else
    {
        o->show_col();
        for (int i = 0; i < v.size(); i++)
            v[i]->show();
    }

    system("pause");
}

void SellerMenu ::show_order()
{
    myVector<Order *> v = o->search_id_seller(me->getID());
    if (v.empty())
        cout << "你还没有订单" << endl;
    else
    {
        o->show_col();
        for (int i = 0; i < v.size(); i++)
            v[i]->show();
    }
}

void MainMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             登录/注册" << endl;
    cout << "          1.用户登录 2.用户注册 3.管理员登录 4.退出程序" << endl;
    cout << "==================================================================" << endl;
    cout << "请选择一个操作" << endl;
    func_menu();
}

void MainMenu::func_menu()
{
    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {

    case (1):
        Sign_in();
        break;
    case (2):
        Sign_up();
        break;
    case (3):
        Sign_in_admin();
        break;
    case (4):
        exit_menu();
        break;
    default:
    {
        cout << "没有这个选项哦" << endl;
        cout << "再给你一次选择的机会" << endl;
    };
    break;
    };
}

void MainMenu::exit_menu()
{
    stop = 1;
    system("cls");
    u->save();
    g->save();
    o->save();
    cout << "欢迎下次光临！" << endl;
}
void MainMenu::Sign_in_admin()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                            管理员登录" << endl;
    cout << "请输入管理员名" << endl;
    string name;
    cin >> name;
    while (name != "admin")
    {
        cout << "输入错误 请再次输入" << endl;
        cin >> name;
    }
    cout << "请输入密码" << endl;
    string pw;
    cin >> pw;
    while (pw != "123456")
    {
        cout << "输入错误 请再次输入" << endl;
        cin >> pw;
    }
    cout << "管理员登录成功！" << endl;
    system("pause");
    adminMenu *am = new adminMenu(u, g, o);
    am->halt();
    return;
}

void MainMenu::Sign_in()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           用户登录" << endl;
    cout << "请输入名字" << endl;
    string name;
    cin >> name;
    User *real = u->search_name(name);
    while (!real) //搜不到
    {
        cout << "用户不存在" << endl;
        system("pause");
        return;
    }
    if (!real->getState())
    {
        cout << "用户被封禁" << endl;
        system("pause");
        return;
    }
    cout << "请输入密码" << endl;
    string pw;
    cin >> pw;
    for (int i = 0; i < 5; i++)
    {
        if (real->getPass() != pw)
        {
            cout << "输入错误,请再次输入" << endl;
            cin >> pw;
        }
        else
        {
            cout << "登录成功！" << endl;
            system("pause");
            UserMenu um = UserMenu(u, g, o, real);
            um.halt();
            return;
        }
    }
    cout << "输入错误已达5次，封禁该用户" << endl;
    u->del(real->getID());
    system("pause");
    return;
}
void MainMenu::Sign_up()
{
    system("cls");
    string name; //昵称
    string pw;   //密码
    string c;    //联系方式
    string ad;   //地址

    cout << "==================================================================" << endl;
    cout << "                           用户注册" << endl;
    cout << "==================================================================" << endl;
    cout << "请输入名字 不超过10个字符，英文字母" << endl;
    name = reg_name();
    while (u->search_name(name) != NULL)
    {
        cout << "名字重复 请再次输入" << endl;
        cin >> name;
    }
    if (strcmp(name.c_str(), "admin") == 0)
    {
        cout << "非法名称" << endl;
        return;
    }

    cout << "请输入密码 （不超过20个字符，只由小写字母和数字组成）" << endl;
    pw = reg_password();
    cout << "请输入联系方式	(不超过20个字符，由数字组成)" << endl;
    c = reg_con();
    cout << "请输入地址 不超过40个字符，英文字母" << endl;
    ad = reg_add();

    string id_new = new_id();
    id_new.insert(0, "U");

    User tmp(id_new, name, pw, c, ad);
    u->add(tmp);

    cout << "注册成功！您的id是" << id_new << endl;
    cout << "即将返回登录..." << endl;
    system("pause");
    Sign_in();
}
