#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsScene>
#include<Marcos.h>
#include<fstream>
#include <vector>
#include<QPixmap>
#include<Marcos.h>
#include<graphscene.h>
#include<QMouseEvent>
#include <QImageReader>
#include<QGraphicsPixmapItem>


class object: public QGraphicsPixmapItem
{
protected:
    int side;
    int tcount;
    int interval;

public:
    int money=10;
    QList<Card*> buff;
    GraphScene *s;

    pair<int,int> absPos;
    pair<int,int> relaPos;
    int health,clever,mental;

    void setPosition(int r,int c);
    virtual QString getString();

    object(GraphScene *s, const QString &icon,int side,int i,int j);

    void setLife(int health, int clever, int mental);
    void changeLife(int health, int clever, int mental);

    virtual void changePic( const QString& s);
    QRectF boundingRect( )const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual void advance(int phase);
    virtual void onSlow(){};
    virtual void onFast(){};

};


class mover:public object
{
protected:

    pair<int,int> dir;
    int count;//位置计数

public:
    int speed;
    mover(GraphScene *s, const QString &icon, int side,int i, int j);
    virtual void updatePos();
    virtual void setSpeed(int s){speed =s;};
    virtual void onSlow();
    virtual void onFast();
};


class fly:public mover
{

public:
    int buftimer=0;
    void setDir(int x,int y ){dir=pair(x,y);};
    fly(GraphScene *s, const QString &icon, int side, int i, int j);
    QString getString(){return QString("");};
    virtual void updatePos();
    virtual void onSlow(){};
    virtual void onFast();
};

class student:public mover
{
protected:

    bool islive();

    int buftimer=0;
    fly* b;
    bool isfrozen=0;
public:
    QString name="鼠鼠";
    bool isable=0;
    void setSpeed(int s);
    student(GraphScene *s, const QString &icon,int i,int j);
    QString getString();
    virtual void onSlow();
    virtual void onFast();
};




class gezi: public object
{
protected:
    const int type;
    QString n;
    int durtime=0;
public:
    bool isbleed=0;
    bool isfrozen=0;
    bool isAll=0;
    int adder;
    gezi( GraphScene *s, int i, int j,int type) ;
    int tower_type;
    void init();

    int getType(){return type;};
    virtual QString getString();
    void act(student* s);

    void pen(int x,int y);

    bool onClick(Card* c);
    bool addCard(Card* c);
    void deCard();
    void addBuf(Card* c);
    void deBuf(Card* c);
    void onClickright();

    void changePic( QString s);

    virtual void advance(int phase);
    virtual void onSlow();
    virtual void onFast();
};


class Card:  public QGraphicsPixmapItem
{
protected:
    QString icon;
    int side;

    QString icon_selected;


    GraphScene *s;
public:
    int num=-1;
    bool interval=0;
    bool adder=0;
    int health,clever,mental;
    bool isAll=0;
    bool isfrozen=0;
    bool isbleed=0;

    int money;
    QString name;
    Card(GraphScene *s, const QString &icon, const QString &icon_selected, int side, int isBuf, const QString &picture,const QString &name);

    void setLife(int health, int clever, int mental);
    int isBuf;//0近战  1 ddl  2 远程 3 buf
    QString picture;

    virtual QString getString();


    void changePic(QString s);
    QRectF boundingRect( )const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual void advance(int phase);
    void onSelected();
    void deSelcted();
    void advance();

};

#endif // OBJECT_H
