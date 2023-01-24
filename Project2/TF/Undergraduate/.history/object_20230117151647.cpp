#include "object.h"
#include "qpainter.h"
#include<QLabel>




object::object()
{
    pic.load(icon);
    setPos(absPos.first,absPos.second);
    s->addItem(this);
    count =0;
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
    painter->drawPixmap(absPos.first,absPos.second,this->pic);
}

void object::advance(int phase)
{
//    count ++;
//    cerr << count ;
//    Debug("  Obj advanced")


}


object::object(GraphScene *s, const QString &icon, int side,int i,int j) : s(s),
    icon(icon),
    side(side)
{
    pic.load(icon);
    pic=pic.scaled(side,side);
    setPosition(i,j);
    s->addItem(this);
    count =0;
}

void object::setPosition(int r, int c)
{
    relaPos.first=r;
    relaPos.second=c;
    absPos=s->get_abs(r,c);
    //    cerr <<absPos.first;
    //    this->setPos(absPos.first,absPos.second);
}

bool student::islive()
{
    return health>0&&mental>0&&clever>0;
}

actor::actor(int health, int clever, int mental) : health(health),
    clever(clever),
    mental(mental)
{}

actor::student(GraphScene *s, const QString &icon, int side, int i, int j): object(s,icon,side,i,j)
{

}

gezi::gezi(int type) : type(type)
{}


mover::student(GraphScene *s, const QString &icon, int side, int i, int j) : actor(s,icon,side,i,j)
{
    this->dir=pair(1,0);
}


void student::advance(int phase)
{
    absPos.first+=dir.first*speed;
    absPos.second+=dir.second*speed;
    relaPos=s->get_rela(absPos.first,absPos.second);
    setPos(absPos.first,absPos.second);
}

void student::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(absPos.first,absPos.second,this->pic);
}


