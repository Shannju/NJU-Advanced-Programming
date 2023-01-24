#include "graphscene.h"


Map::Map()
{}

Map::Map(int r,int c ):colunm(c),row(r)
{
    for (int i = 0; i < colunm; ++i)
    {
        vector <int> tmp (row);
        a.push_back(tmp);
    }
    read_file();

}

void Map::init()
{
    for (int i = 0; i < colunm; ++i)
        for (int j = 0; j < row; ++j)
            a[i][j]= 0;
    write_file();

}

void Map::read_file()
{
    ifstream ifs;
    ifs.open(MAP_File, ios::in);
    if (!ifs.is_open())
    {
        Debug("file map.txt dont exist, new one created.")
                fstream ofs;
        ofs.open(MAP_File, ios::out);
        ofs.close();
        return;
    }
    for (int i = 0; i < colunm; ++i)
        for (int j = 0; j < row; ++j)
        {
            ifs >>  a[i][j] ;
            if (a[i][j] == 5)
                startPos =pair(i,j);
        }
    ifs.close();
}

void Map::write_file()
{
    fstream ofs;
    ofs.open(MAP_File, ios::out);
    for (int i = 0; i < colunm; ++i)
    {
        ofs << endl;
        for (int j = 0; j < row; ++j)
            ofs<< a[i][j] <<" ";
    }
    ofs.close();
}

void Map::print_file()
{
    for (int i = 0; i < colunm; ++i)
    {
        cerr <<endl;
        for (int j = 0; j < row; ++j)
            cerr << a[i][j];
    }
}


GraphScene::GraphScene(QObject *parent)
    : QGraphicsScene{parent},u(150),   l(45), space(5),side(80)
{
    auto back_image_orgin = QImage(":/image/blackboard.png");
    auto  back_image = back_image_orgin.scaled(1160,650);
    QPixmap p =  QPixmap ::fromImage(*&back_image);
    addPixmap(p);
    moneytext =new QGraphicsTextItem  ("经费："+QString::number(money)+"万元");
    moneytext->setDefaultTextColor(QColor("#FFFFFF"));
    addItem(moneytext);

    init();
}

void GraphScene::ms()
{
    QString tmp="在您任期中：毕业生共"+ QString::number(a+b)+ " 名 其中优秀"+ QString::number(a)+"人 肄业"+ QString::number(c)+"人 退学"+ QString::number(d)+"人 "+"剩余经费 "+ QString::number(money)+"万元";

    QMessageBox mb("述职报告",
                   tmp,
                   QMessageBox::NoIcon,
                   QMessageBox::Yes | QMessageBox::Default,
                   QMessageBox::NoButton,
                   QMessageBox::NoButton);
    QPixmap exportSuccess("://image/zhishi.png");
    mb.setIconPixmap(exportSuccess.scaled(80,80));
    mb.exec();


}

void GraphScene::init()
{
    //set Cards

    Card* c = new Card(this,":/image/yel.png",":/image/yel_selected.png",50,0,QString(":/image/s_yel.png"),QString("专业课"));
    c->setPos(220,10);
    c->setLife(0,+4,+1);

    c = new Card(this,":/image/blue.png",":/image/blue_selected.png",50,0,QString(":/image/s_blue.png"),QString("通识课"));
    c->setPos(310,10);
    c->setLife(0,+1,+4);

    c = new Card(this,":/image/green.png",":/image/green_selected.png",50,0,QString(":/image/s_green.png"),QString("体育课"));
    c->setPos(220,70);
    c->setLife(+4,+1,+2);

    c = new Card(this,":/image/pink.png",":/image/pink_selected.png",50,0,QString(":/image/s_pink.png"),QString("校庆日"));
    c->setPos(310,70);
    c->setLife(+2,-2,+2);


    c = new Card(this,":/image/ddl.png",":/image/selected.png",50,1,QString(":/image/s_red.png"),QString("Deadline"));//ddl
    c->setPos(480,10);
    c->money=5;
    c->setLife(-1,-1,-1);



    c = new Card(this,":/image/far1.png",":/image/selected.png",80,2,QString(":/image/far1.png"),QString("活动中心"));//远程
    c->setPos(560,10);

    c = new Card(this,":/image/far2.png",":/image/selected.png",80,2,QString(":/image/far2.png"),QString("修铁丝网"));//远程
    c->setPos(640,10);

    c = new Card(this,":/image/far3.png",":/image/selected.png",80,2,QString(":/image/far3.png"),QString("绿化校园"));//远程
    c->setPos(720,10);


    c = new Card(this,":/image/buf1.png",":/image/selected.png",50,3,QString(""),QString("红榜转黑"));//词缀
    c->setPos(810,10);
    c->num=0;
    c->setLife(-1,-1,-1);
    c->interval=1;
    card_list.append(c);

    c = new Card(this,":/image/buf2.png",":/image/selected.png",50,3,QString(""),QString("次次点到"));//词缀
    c->setPos(870,10);
    c->num=0;
    c->setLife(-1,+2,-1);
    c->isAll=1;
    card_list.append(c);

    c = new Card(this,":/image/buf3.png",":/image/selected.png",50,3,QString(""),QString("线上教学"));//词缀
    c->isfrozen=1;
    c->num=0;
    c->setPos(930,10);
    c->setLife(+2,-2,+1);
    card_list.append(c);

    c = new Card(this,":/image/buf4.png",":/image/selected.png",50,3,QString(""),QString("增加预算"));//词缀
    c->setLife(+1,+1,+1);
    c->num=0;
    c->isbleed=1;
    c->setPos(420,10);
    card_list.append(c);


    m =new Map(12,5);//row col
    for (int i=0;i<m->colunm;i++)
        map.append(QList<gezi*>());
    load_map();
}

void GraphScene::load_map()
{
    for (int i =0;i<m->colunm;i++)
    {
        for (int j =0;j<m->row;j++)
        {
            int type =m->a[i][j];
            gezi* tmp = new gezi(this,i,j,type);
            map[i].append(tmp);
        }

    }
}

void GraphScene::setmoney(int m)
{
    money = m;
    moneytext->setPlainText( "经费："+QString::number(money)+"万元");
}

pair<int, int> GraphScene::get_abs(int r, int c)
{
    return pair(l+(space+side)*c,u+(space+side)*r);
}

pair<int, int> GraphScene::get_rela(int x, int y)
{
    return pair((y-u)/(space+side),(x-l)/(space+side));
}

gezi *GraphScene::get_gezi(int x, int y)
{
    pair<int, int>  r = get_rela(y,x);
    return map[r.first][r.second];
}

void GraphScene::advance(int phase)
{


    if (randomBool(4))
        newEnemy();

}

void GraphScene::newEnemy()
{
    money+=1;
    int i= m->startPos.first;
    int j = m->startPos.second;
    int num = randomInt(0,4);
    auto* tmp = new student(this,Enemy_list[num],i,j);

    if (randomBool(4))
    {
        tmp->isable=1;
        tmp->name="摆子哥";
    }

    tmp->speed=randomInt(1,2);
    if (tmp->speed>1)
    {
        tmp->name="佬";
    }

    stu.append(tmp);
}

void GraphScene::addCard(Card *c)
{
    currentCard=c;
    c->onSelected();
    qDebug() << "currentcard updated";
}



