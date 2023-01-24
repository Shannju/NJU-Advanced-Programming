#ifndef BUF_H
#define BUF_H
#include<QGraphicsItem>
#include<Marcos.h>

//对于对象的一种改变
class buf: public QGraphicsItem
{
protected:
    QString name;

public:
    buf(QWidget *parent = nullptr);
    buf(const QString &name, QWidget *parent = nullptr);

    QString getName(){return name;};
private slots:
//    virtual void mousePressEvent(QMouseEvent* event);//点击鼠标
};

class tower:public buf
{
protected:
    QString pic;
    int health,clever,mental;
public:
    tower(const QString &pic, int health, int clever, int mental, const QString &name);
};
class ddl:public buf
{
protected:
};

class towerBuf:public buf
{

};

class stuBuf:public buf
{

};
#endif // BUF_H
