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
    cout << "                             ����" << endl;
    cout << "1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� " << endl;
    cout << "6.����û�     7.ע��" << endl;
    cout << "==================================================================" << endl;
    cout << "��ѡ��һ������" << endl;
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
        cout << "��Ʒ�б�����" << endl;
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
            cout << "û�����ѡ��Ŷ" << endl;
            cout << "�ٸ���һ��ѡ��Ļ���" << endl;
        };
        break;
    }
    system("pause");
    return;
}

void adminMenu::del_user()
{
    cout << "==================================================================" << endl;
    cout << "                              ����û�" << endl;
    cout << "�������û�������" << endl;
    string n;
    cin >> n;

    User *real = u->search_name(n);
    if (!real) //�Ѳ���
    {
        cout << "�û�������" << endl;
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
        cout << "�û�������" << endl;

        return;
    }
    break;
    case 1:
    {
        cout << "�û� " << id << " �Ѿ����" << endl;

        return;
    }
    case 2:
    {
        myVector<Goods *> v = g->search_id_seller(id);
        for (int i = 0; i < v.size(); i++)
            v[i]->kill();
        cout << "�ѽ��û� " << id << " ���" << endl;
    }

    default:
        break;
    }
}

void adminMenu::off_shelf()
{
    cout << "==================================================================" << endl;
    cout << "                             �¼���Ʒ" << endl;
    cout << "�������¼���Ʒ��id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);

    if (!temp) //����removed 0, onAuction 1
    {
        cout << "��Ʒ������" << endl;

        return;
    }
    if (temp->getState() == 0)
    {
        cout << "��Ʒ " << id << " �Ѿ��¼�" << endl;

        return;
    }
    if (temp->getState() == 1)
    {
        temp->setState(0);
        cout << "��Ʒ " << id << " �¼ܳɹ�" << endl;

        return;
    }
}

void adminMenu::exit_menu() //ע��
{
    stop = 1;
    cout << "���˳�����Աϵͳ" << endl;
    system("pause");
}

void RealMenu::check() //�˵���������check
{
    g->check(u, o);
}

void RealMenu::search_menu()
{
    cout << "��������Ʒ������" << endl;
    string name;
    cin >> name;
    myVector<Goods *> v = g->fuzzy(name);
    if (v.empty())
    {
        cout << "��Ʒ������" << endl;
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
    cout << "���˳����ϵͳ" << endl;
    system("pause");
    // this->User_Menu_show();
}
void UserMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             �û��˵�" << endl;
    cout << "          1.ע����¼ 2.������� 3.�������� 4.������Ϣ����" << endl;
    cout << "==================================================================" << endl;
    cout << "��ѡ��һ������" << endl;
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
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;

        break;
    };
    }

    return;
}

void UserMenu::inf()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                             ������Ϣ" << endl;
    cout << "              1.�鿴��Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�����" << endl;
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
        cout << "������Ϣ����" << endl;
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
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
        inf();
    };
    }
    inf();
}

void UserMenu::add_money()
{
    cout << "==================================================================" << endl;
    cout << "                             ��ֵ" << endl;
    cout << "����������" << endl;
    string pw;
    cin >> pw;
    int i = 0;
    for (; i < 5; i++)
    {
        if (me->getPass() != pw)
        {
            cout << "�������,���ٴ�����" << endl;
            cin >> pw;
        }
        else
            break;
    }
    if (i == 5)
    {
        cout << "��������Ѵ�5�Σ�������û�" << endl;
        u->del(me->getID());
        system("pause");
        return;
    }
    else
    {
        cout << "��������" << endl;
        string ns;
        cin >> ns;
        int n = atof(ns.c_str());
        if (0 < n)
        {
            me->addBalance(n);
            cout << "�ɹ���ֵ" << n << "Ԫ" << endl;
            me->showBalance();
        }
        else
            cout << "��ֵʧ��" << endl;
    }
    system("pause");
}

void UserMenu::change_show()
{
    cout << "����������" << endl;
    string pw;
    cin >> pw;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (me->getPass() != pw)
        {
            cout << "�������,���ٴ�����" << endl;
            cin >> pw;
        }
        else
            break;
    }
    if (i == 5)
    {
        cout << "��������Ѵ�5�Σ�������û�" << endl;
        u->del(me->getID());
        exit_menu();
        return;
    }

    cout << "==================================================================" << endl;
    cout << "                             �޸���Ϣ" << endl;
    cout << "          1.�޸����� 2.�޸����� 3.�޸���ϵ��ʽ 4.�޸ĵ�ַ" << endl;
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
        cout << "����������" << endl;
        me->setName(reg_name());
    };
    break;
    case (2):
    {
        cout << "���������� ��������20���ַ���ֻ��Сд��ĸ��������ɣ�" << endl;
        me->setPass(reg_password());
    };
    break;
    case (3):
    {

        cout << "��������ϵ��ʽ	(������20���ַ������������)" << endl;
        me->setContact(reg_con());
    };
    break;
    case (4):
    {
        cout << "�������ַ	" << endl;
        me->setAddress(reg_add());
    }
    break;
    default:
    {
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
        this->change_show();
    };
    }
    cout << "�޸ĳɹ�" << endl;
    cout << "����������һ��" << endl;
    system("pause");
}

void BuyerMenu::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           ��Ҳ˵�" << endl;
    cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ�������Լ���" << endl;
    cout << "5.�����û������� " << endl;
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
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
    };
    break;
    }
    system("pause");
}

void BuyerMenu::auction()
{
    cout << "==================================================================" << endl;
    cout << "                         ������Ʒ" << endl;
    cout << "��Ʒ�б�����" << endl;
    g->show();
    cout << "�����뾺����Ʒ��id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id); //�ҵ���ƷΪtemp

    while (!temp)
    {
        cout << "��Ʒ������" << endl;
        system("pause");
        return;
    }
    User *seller = u->search(temp->getSID()); //�ҵ�����Ϊseller

    if (temp->getState() == 0)
    {
        cout << "��Ʒ���ɾ���" << endl;
        system("pause");

        return;
    }

    if (temp->getNum() <= 0)
    {
        cout << "��Ʒ�Ѿ��ۿ�" << endl;
        system("pause");

        return;
    }

    if (temp->getSID() == me->getID())
    {
        cout << "���ɾ����Լ�����Ʒ" << endl;
        system("pause");

        return;
    }
    int num;
    cout << "�����뾺������" << endl;
    num = reg_inum();

    double offer;
    cout << "�����뾺�ļ۸�" << endl;
    offer = reg_dnum();
    if (offer < temp->getPrice())
    {
        cout << "���ļ۸񲻵�������Ʒ�׼ۣ�" << temp->getPrice() << endl;
        system("pause");
        return;
    }
    if (offer * num > me->getBalance())
    {
        cout << "���� ���ֵ" << endl;
        system("pause");
        return;
    }
    time_t t = getTime_value();
    temp->auction(u, num, offer, t, me->getID());
    cout << "�ɹ����ı���Ʒ" << endl;
}
void BuyerMenu::exit_menu()
{
    stop = 1;
    cout << "���˳����ϵͳ" << endl;
    system("pause");
}

void SellerMenu ::show_menu()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           ���Ҳ˵�" << endl;
    cout << "1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ" << endl;
    cout << "5.�鿴��ʷ���� 6.�����û�����" << endl;
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
        cout << "������Ʒ�б�����" << endl;
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
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
    };
    break;
    }
    system("pause");
}
void SellerMenu ::exit_menu()
{
    stop = 1;
    system("cls");
    cout << "���˳�����ϵͳ" << endl;
    system("pause");
}
void SellerMenu ::add_goods()
{
    cout << "==================================================================" << endl;
    cout << "                           ������Ʒ" << endl;
    cout << "==================================================================" << endl;
    string id_new = new_id();
    id_new.insert(0, "M");

    string name;
    cout << "��������Ʒ����" << endl;
    cin >> name;
    string s_price;
    cout << "��������Ʒ�۸�" << endl;
    double price = reg_dnum();
    cout << "��������Ʒ����" << endl;
    int number = reg_inum();
    string dis;
    cout << "����������" << endl;
    getchar();
    getline(cin, dis);
    if (regex_search(dis, regex("\\s")))
    {
        cout << "���ô��пո�Ŷ ���ٴ�����" << endl;
        cin >> dis;
    }
    Goods gitem(id_new, name, price, number, dis, me->getID()); //���충��
    g->add(gitem);
}

void SellerMenu ::show_my_goods()
{
    cout << "==================================================================" << endl;

    myVector<Goods *> v = g->search_id_seller(me->getID());
    if (v.empty())
        cout << "�㻹û���ϼ���Ʒ" << endl;
    else
    {
        g->show_col();
        if (g->ls.empty())
            cout << "�б�Ϊ��" << endl;
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
    cout << "                             �޸���Ʒ" << endl;
    cout << "�������޸���Ʒ��id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);
    while (!temp)
    {
        cout << "��Ʒ������" << endl;
        system("pause");

        return;
    }
    if (temp->getNum() <= 0)
    {
        cout << "��Ʒ���ۿ� �����޸�" << endl;
        system("pause");

        return;
    }
    if (temp->getState() == 0)
    {
        cout << "��Ʒ���¼� �����޸�" << endl;
        system("pause");

        return;
    }
    cout << "��Ҫ�޸ģ�1.���� 2.�۸� 3.����" << endl;

    string chioce;
    cin >> chioce;
    int n = atof(chioce.c_str());
    switch (n)
    {
    case (1):
    {
        string new_name;
        cout << "���������֣�������10���ַ���Ӣ����ĸ��" << endl;
        cin >> new_name;
        regex name0("^[a-zA-Z]{1,10}$");
        while (!regex_match(new_name, name0))
        {
            cout << "�������� ���ٴ�����" << endl;
            cin >> new_name;
        }
        temp->setName(new_name);
    };
    break;
    case (2):
    {
        string s_price;
        cout << "������۸�(0-1wԪ)" << endl;
        cin >> s_price;
        regex p0("^[0-9]{1,5}$");
        int price = atof(s_price.c_str());
        while ((!regex_match(s_price, p0)) || (price <= 0))
        {
            cout << "�������� ���ٴ�����" << endl;
            cin >> s_price;
            price = atof(s_price.c_str());
        }
        temp->setPrice(price);
    };
    break;
    case (3):
    {
        string dis;
        cout << "����������" << endl;
        getchar();
        getline(cin, dis);
        temp->setDis(dis);
        break;
    }
    default:
    {
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
        change_show();
        return;
    }
    break;
    }
    cout << "�޸ĳɹ�" << endl;
}

void SellerMenu ::off_shelf()
{
    cout << "==================================================================" << endl;
    cout << "                             �¼���Ʒ" << endl;
    show_my_goods();
    cout << "�������¼���Ʒ��id" << endl;
    string id;
    cin >> id;
    Goods *temp = g->search(id);
    while (!temp)
    {
        cout << "��Ʒ������" << endl;
        system("pause");
        return;
    }

    if (temp->getState() == 0)
    {
        cout << "��Ʒ���¼�" << endl;
        system("pause");

        return;
    }
    if (temp->getNum() <= 0)
    {
        cout << "��Ʒ���ۿ�" << endl;
        system("pause");
        return;
    }
    if (strcmp(temp->getSID().c_str(), me->getID().c_str()) != 0)
    {
        cout << "��ֻ���¼��Լ�����Ʒ" << endl;
        system("pause");
        return;
    }
    temp->setState(0);
    cout << "�¼ܳɹ�" << endl;
}

void BuyerMenu ::show_order()
{
    myVector<Order *> v = o->search_id_buyer(me->getID());
    if (v.empty())
        cout << "�㻹û�ж���" << endl;
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
        cout << "�㻹û�ж���" << endl;
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
    cout << "                             ��¼/ע��" << endl;
    cout << "          1.�û���¼ 2.�û�ע�� 3.����Ա��¼ 4.�˳�����" << endl;
    cout << "==================================================================" << endl;
    cout << "��ѡ��һ������" << endl;
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
        cout << "û�����ѡ��Ŷ" << endl;
        cout << "�ٸ���һ��ѡ��Ļ���" << endl;
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
    cout << "��ӭ�´ι��٣�" << endl;
}
void MainMenu::Sign_in_admin()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                            ����Ա��¼" << endl;
    cout << "���������Ա��" << endl;
    string name;
    cin >> name;
    while (name != "admin")
    {
        cout << "������� ���ٴ�����" << endl;
        cin >> name;
    }
    cout << "����������" << endl;
    string pw;
    cin >> pw;
    while (pw != "123456")
    {
        cout << "������� ���ٴ�����" << endl;
        cin >> pw;
    }
    cout << "����Ա��¼�ɹ���" << endl;
    system("pause");
    adminMenu *am = new adminMenu(u, g, o);
    am->halt();
    return;
}

void MainMenu::Sign_in()
{
    system("cls");
    cout << "==================================================================" << endl;
    cout << "                           �û���¼" << endl;
    cout << "����������" << endl;
    string name;
    cin >> name;
    User *real = u->search_name(name);
    while (!real) //�Ѳ���
    {
        cout << "�û�������" << endl;
        system("pause");
        return;
    }
    if (!real->getState())
    {
        cout << "�û������" << endl;
        system("pause");
        return;
    }
    cout << "����������" << endl;
    string pw;
    cin >> pw;
    for (int i = 0; i < 5; i++)
    {
        if (real->getPass() != pw)
        {
            cout << "�������,���ٴ�����" << endl;
            cin >> pw;
        }
        else
        {
            cout << "��¼�ɹ���" << endl;
            system("pause");
            UserMenu um = UserMenu(u, g, o, real);
            um.halt();
            return;
        }
    }
    cout << "��������Ѵ�5�Σ�������û�" << endl;
    u->del(real->getID());
    system("pause");
    return;
}
void MainMenu::Sign_up()
{
    system("cls");
    string name; //�ǳ�
    string pw;   //����
    string c;    //��ϵ��ʽ
    string ad;   //��ַ

    cout << "==================================================================" << endl;
    cout << "                           �û�ע��" << endl;
    cout << "==================================================================" << endl;
    cout << "���������� ������10���ַ���Ӣ����ĸ" << endl;
    name = reg_name();
    while (u->search_name(name) != NULL)
    {
        cout << "�����ظ� ���ٴ�����" << endl;
        cin >> name;
    }
    if (strcmp(name.c_str(), "admin") == 0)
    {
        cout << "�Ƿ�����" << endl;
        return;
    }

    cout << "���������� ��������20���ַ���ֻ��Сд��ĸ��������ɣ�" << endl;
    pw = reg_password();
    cout << "��������ϵ��ʽ	(������20���ַ������������)" << endl;
    c = reg_con();
    cout << "�������ַ ������40���ַ���Ӣ����ĸ" << endl;
    ad = reg_add();

    string id_new = new_id();
    id_new.insert(0, "U");

    User tmp(id_new, name, pw, c, ad);
    u->add(tmp);

    cout << "ע��ɹ�������id��" << id_new << endl;
    cout << "�������ص�¼..." << endl;
    system("pause");
    Sign_in();
}
