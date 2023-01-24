#include "object.h"
#include "qpainter.h"
#include<QLabel>




object::object()
{
    pic.load(icon);
    setPos(absPos.first,absPos.second);
    s->addItem(this);
    setToolTip(QString("提示信息"));
    setCursor(Qt::OpenHandCursor);    //改变光标形状,光标变为了手型

}

void object::changePic(QString s)
{
    icon =s;
}

QRectF object::boundingRect() const
{
    return QRectF(0,0,side,side);
}

void object::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPos(absPos.first,absPos.second);
    painter->drawPixmap(0,0,this->pic);
}

void object::advance(int phase)
{

}

QString object::getString()
{
    return QString("Empty Object");
}


object::object(GraphScene *s, const QString &icon, int side,int i,int j) : s(s),
    icon(icon),
    side(side)
{
    setLife(90,0,0);
    pic.load(icon);
    pic=pic.scaled(side,side);
    setPosition(i,j);
    s->addItem(this);

}

void object::setPosition(int r, int c)
{
    relaPos.first=r;
    relaPos.second=c;
    absPos=s->get_abs(r,c);

}

bool student::islive()
{
    return health>0&&mental>0&&clever>0;
}



void object::setLife(int health, int clever, int mental)
{
    this->health=health;
    this->clever=clever;
    this->mental=mental;
}

void object::changeLife(int health, int clever, int mental)
{
    this->health+=health;
    this->clever+=clever;
    this->mental+=mental;
}

QString student::getString()
{
    QString s;
    if (health<30|| mental<30|| clever<30)
        s+=QString("【退学边缘】 ");
    else if (health<60|| mental<60|| clever<60)
        s+=QString("【得过且过】 ");
    else
        s+=QString("【勃勃生机】 ");
    s+=QString("健康 ")+QString::number(health)+QString(" 智慧 ")+QString::number(clever)+QString(" 存在 ")+QString::number(mental);
    return s;
}



void student::advance(int phase)
{
    updatePos();
    update();
    s->map[relaPos.first][relaPos.second]->act(this);
}



void mover::updatePos()
{
    //    cerr << "moving "<< dir.first << dir.second<<endl;
    if (count>=(side+5))
    {
        count = 0;
        int ge= s->map[relaPos.first][relaPos.second]->getType();
        dir=Dir_list[ge];
        return ;
    }
    absPos.first+=dir.first*speed/2;
    absPos.second+=dir.second*speed/2;
    relaPos=s->get_rela(absPos.first,absPos.second);
    setPos(absPos.first,absPos.second);
    count +=max(dir.first,dir.second)*speed;
}

void mover::advance(int phase)
{
    updatePos();
    update();
}



void student::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPos(absPos.first,absPos.second);
    painter->drawPixmap(0,0,this->pic);
}



student::student( GraphScene *s, const QString &icon, int i, int j) :mover(s, icon, 80, i, j),count(0)
{
    this->setZValue(1);
    this->dir=pair(1,0);
    speed =1;
    setLife(90,randomInt(80,100),randomInt(80,100));
    setToolTip(getString());
    setCursor(Qt::OpenHandCursor);    //改变光标形状,光标变为了手型
}

gezi::gezi(GraphScene *s, int i, int j, int type):object(s, Color_list[type], 80, i, j),
    type(type)
{
    setToolTip(getString());
    setCursor(Qt::OpenHandCursor);    //改变光标形状,光标变为了手型
}



void gezi::advance(int phase)
{
    if (phase)
    {

        update();
    }

}

void gezi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPos(absPos.first,absPos.second);
    painter->drawPixmap(0,0,this->pic);
}

QString gezi::getString()
{
    QString s;
    switch (type) {
    case 0:
    {
        s+=QString ("空格");
    } break;
    default:
    {
        s+=QString ("空闲时间");
    }    break;
    }
    for (auto i:buff)
    {
        s+=i->getName();
        s+=QString (" ");
    }
    return s;
}

void gezi::act(student *s)
{
    //    cerr<< "gezi acted!"<<endl;
    s->changeLife(health,clever,mental);
}

mover::mover(GraphScene *s, const QString &icon,int side, int i, int j) : object(s, icon,side, i, j),
    speed(1),
    count(0)
{
    this->dir=pair(0,0);
}
