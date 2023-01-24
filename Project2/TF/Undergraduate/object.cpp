#include "object.h"
#include "qpainter.h"
#include<QLabel>


QRectF object::boundingRect() const
{
    return QRectF(0,0,side,side);
}

void object::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPos(absPos.first,absPos.second);
    //    painter->drawPixmap(0,0,this->pic);
    painter->drawPixmap(0,0,this->pixmap());
}

void object::advance(int phase)
{
    tcount ++;
    if (tcount==interval)
    {
        tcount=0;
        onSlow();
    }
    onFast();
}


QString object::getString()
{
    return QString("Empty Object");
}


object::object(GraphScene *s, const QString &icon, int side,int i,int j) : s(s),
    side(side),tcount(0),interval(20)
{

    setPixmap(QPixmap(icon).scaled(side,side));
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

void student::setSpeed(int s)
{
    if (name=="佬"&&s==1)
    {
        speed=randomInt(1,2);
    }
    else
        speed=s;
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
    setToolTip(getString());
}

void object::changePic(const QString &s)
{
    setPixmap(QPixmap(s).scaled(side,side));
}

QString student::getString()
{
    QString s=name;
    if (health<0|| mental<0|| clever<0)
        hide();
    else if (health<30|| mental<30|| clever<30)
    {

        s+=QString("【退学边缘】 ");
    }
    else if (health<60|| mental<60|| clever<60)
        s+=QString("【得过且过】 ");
    else
        s+=QString("【勃勃生机】 ");


    s+=QString("健康 ")+QString::number(health)+QString(" 智慧 ")+QString::number(clever)+QString(" 存在 ")+QString::number(mental);
    return s;
}


void student::onSlow()
{
    if(buftimer>0&&b)
    {
        changeLife(b->health,b->clever,b->mental);
        buftimer--;
    }
    if(buftimer==0)
    {
        b=nullptr;
    }
}

void student::onFast()
{
    if (!this->isVisible())
        return;
    if (s->map[relaPos.first][relaPos.second]->getType()==6)
    {

        if (health<0|| mental<0|| clever<0)
        {
            s->d++;
            s->setmoney(s->money-1);
            return ;
        }
        else if (health<30|| mental<30|| clever<30)
            s->c++;
        else if (health<60|| mental<60|| clever<60)
            s->b++;
        else
        {

            s->a++;
            s->setmoney(s->money+5);

        }
        int tmps=s->card_list.size();
        s->card_list[randomInt(0,tmps-1)]->num+=1;
        hide();

    }
    QList<QGraphicsItem *> list=collidingItems(Qt::IntersectsItemBoundingRect);
    for (QGraphicsItem  * i :list)
    {
        if (i->zValue()==3)
        {
            fly* tmp = qgraphicsitem_cast<fly*>(i);
            changeLife(tmp->health,tmp->clever,tmp->mental);
            qDebug()<<"收到子弹伤害";
            if(tmp->buftimer)
            {
                buftimer=tmp->buftimer;
                b=tmp;
                qDebug()<<"收到子弹持续伤害";
            }
            delete tmp;
        }
    }
    updatePos();

}

void mover::updatePos()
{
    //    cerr<<"here is speed " << speed<<endl;
    absPos.first+=dir.first*speed;
    absPos.second+=dir.second*speed;
    relaPos=s->get_rela(absPos.first,absPos.second);
    setPos(absPos.first,absPos.second);
    count +=max(dir.first,dir.second)*speed;
    if (count>=(side+5))
    {
        count = 0;
        int ge= s->map[relaPos.first][relaPos.second]->getType();

        dir=Dir_list[ge];
        return;
    }

}


void mover::onSlow()
{

}

void mover::onFast()
{
    updatePos();
    update();
}



student::student( GraphScene *s, const QString &icon, int i, int j) :mover(s, icon, 80, i, j)
{
    this->setZValue(2);
    this->dir=pair(1,0);
    speed =1;
    setLife(90,randomInt(80,100),randomInt(80,100));
    setToolTip(getString());
}



gezi::gezi(GraphScene *s, int i, int j, int type):object(s, Color_list[type], 80, i, j),
    type(type),durtime(0)
{
    if (type==0)
        n=QString("空格");
    else
        n=QString("空闲时间");
    tower_type=-1;
    setZValue(1);
    setLife(-1,-1,-1);
    setToolTip(getString());

}

void gezi::init()
{
    if (type==0)
        n=QString("空格");
    else
        n=QString("空闲时间");
    setLife(-1,-1,-1);
    changePic(Color_list[type]);
    durtime=0;
    buff.empty();
}

QString gezi::getString()
{
    QString s=n;
    for (Card*i:buff)
    {
        s+=QString (" ");
        s+=i->name;
        qDebug()<<buff.size();
    }
    return s;
}

void gezi::act(student *s)
{


}

void gezi::pen(int x, int y)
{
    durtime--;
    auto* f = new fly(s,QString(":/image/heart.png"),10,relaPos.first,relaPos.second);
    if (isbleed)
        f->buftimer=5;
    f->setDir(x,y);
}

bool gezi::onClick(Card *c)
{
    c->num--;
    if (c->picture!="")
        changePic(c->picture);
    if (c->isBuf==0)//class
    {
        n=c->name;
        tower_type=c->isBuf;
        durtime= 200;
        setToolTip(getString());
        s->setmoney(s->money-this->money);
        return 1;

    }
    else if (c->isBuf==1)//ddl
    {
        n=c->name;
        tower_type=c->isBuf;
        durtime= type*10;
        setToolTip(getString());
        s->setmoney(s->money-this->money);
        return 1;

    }
    else if (c->isBuf==2)//buildings
    {

        if (type==0)
        {
            s->setmoney(s->money-this->money);
            n=c->name;
            tower_type=c->isBuf;
            durtime= 300;
            setToolTip(getString());
            interval=100;
            return 1;

        }
    }
    else if (c->isBuf==3)//buf
    {
        if (tower_type==0||tower_type==1)//
        {
            qDebug()<<"getbuf";
            addCard(c);
            durtime= 10000;
            setToolTip(getString());
            return 1;
        }
        if (tower_type==2)//
        {
            qDebug()<<"getbuf";
            addCard(c);
            durtime= 10000;
            setToolTip(getString());
            return 1;
        }
    }

    return 0;

}

bool gezi::addCard(Card *c)
{
    if(buff.size()<2)
    {
        buff.append(c);
    }
    else{
        deCard();
        buff.append(c);
        cerr<< "buff full, remove the first one"<<endl;
    }
    addBuf(c);
}

void gezi::deCard()
{
    deBuf(buff.takeFirst());
    buff.removeFirst();
}


void gezi::addBuf(Card *c)
{
    setLife(c->health,c->clever,c->mental);
    if (c->interval)
        this->interval/=2;
    if (c->adder)
        this->adder*=2;
    if (tower_type==2&&c->isbleed)
        isbleed=1;
    if (c->isfrozen)
        isfrozen=1;
}

void gezi::deBuf(Card *c)
{
    setLife(-c->health,-c->clever,-c->mental);
    if (c->interval)
        this->interval*=2;
    if (c->adder)
        this->adder/=2;
    if (tower_type==2&&c->isbleed)
        isbleed=0;
    if (c->isfrozen)
        isfrozen=0;
}

void gezi::onClickright()
{
    if(buff.size()>0)
        deCard();
    else{
        init();
    }

}

void gezi::changePic(QString s)
{
    setPixmap(QPixmap(s).scaled(side,side));
}

void gezi::advance(int phase)
{
    if (durtime==0)
        return;
    tcount ++;
    if (tcount==interval)
    {
        tcount=0;
        onSlow();
    }
    onFast();
}

void gezi::onSlow()
{
    if (durtime==0)
    {
        init();
    }
    QList<QGraphicsItem *> list=collidingItems(Qt::IntersectsItemBoundingRect);
    for (QGraphicsItem  * i :list)
    {
        //        qDebug()<<"人数"<<list.size();
        if (i->zValue()==2)
        {
            this->durtime--;
            student* tmp = qgraphicsitem_cast<student*>(i);
            if(tmp->isable&&randomBool(3))
            {
                tmp->setSpeed(1);
                continue;
            }
            tmp->changeLife(health,clever,mental);
            if(tower_type == 1)
            {
                durtime-=tmp->clever%3;
                tmp->setSpeed(0);
                if (durtime<=0)
                {
                    tower_type=0;
                    tmp->setSpeed(1);
                    init();
                }
            }
            else
                tmp->setSpeed(1);

            if(isfrozen)
            {
                qDebug()<<"开展冷冻"<<tmp->speed;
                tmp->setSpeed(randomBool(2));
            }
            if(!isAll)
                break;

        }
    }
    if (tower_type==2)
    {
        pen(1,1);
        pen(-1,1);
        pen(-1,-1);
        pen(1,-1);
    }


}

void gezi::onFast()
{
    //    QList<QGraphicsItem *> list=collidingItems(Qt::IntersectsItemBoundingRect);
    //    for (QGraphicsItem  * i :list)
    //    {
    //        if (i->zValue()==2)
    //        {
    //            student* tmp = qgraphicsitem_cast<student*>(i);
    //            if(tower_type == 1)
    //            {
    //                durtime-=tmp->clever%30;
    //                if (tmp->isable&&randomBool(3))
    //                    return;
    //                else
    //                    tmp->speed=0;
    //            }
    //        }
    //    }
}


mover::mover(GraphScene *s, const QString &icon,int side, int i, int j) : object(s, icon,side, i, j),
    count(0)
{
    this->dir=pair(0,0);
   s->setmoney(s->money-this->money);
}




Card::Card(GraphScene *s, const QString &icon, const QString &icon_selected, int side, int isBuf, const QString &picture, const QString &name):
    side(side),icon(icon),
    icon_selected(icon_selected),
    isBuf(isBuf),
    picture(picture),
    s(s),
    name(name)
{
    setZValue(1);
    QPixmap pic(icon);
    setPixmap(pic.scaled(pic.width()*side/pic.height(),side));
    s->addItem(this);

}

void Card::setLife(int health, int clever, int mental)
{
    this->health=health;
    this->clever=clever;
    this->mental=mental;
}


QString Card::getString()
{
}

void Card::changePic(QString s)
{
    QPixmap pic(s);
    setPixmap(pic.scaled(pic.width()*side/pic.height(),side));
}

QRectF Card::boundingRect() const
{
    QPixmap pic(icon);
    return QRectF(0,0,pic.width()*side/pic.height(),side);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,this->pixmap());
}

void Card::advance(int phase)
{
    if (num==0)
        hide();
    else
        show();
}

void Card::onSelected()
{
    changePic(icon_selected);
}

void Card::deSelcted()
{
    changePic(icon);
}

void Card::advance()
{
    if (num!=0)
        show();
}



fly::fly(GraphScene *s, const QString &icon, int side, int i, int j) : mover(s, icon, side, i, j)
{
    interval=100;
    setZValue(3);
    speed =1;

    this->dir=pair(1,0);
    speed =1;
    setLife(90,randomInt(80,100),randomInt(80,100));
    setToolTip(getString());
    setCursor(Qt::OpenHandCursor);    //改变光标形状,光标变为了手型

}

void fly::updatePos()
{
    absPos.first+=dir.first*speed;
    absPos.second+=dir.second*speed;
    relaPos=s->get_rela(absPos.first,absPos.second);
    setPos(absPos.first,absPos.second);
    if (absPos.second<130||absPos.second>630||absPos.first<0||absPos.first>1130)
    {
        setSpeed(0);
        hide();

    }

}

void fly::onFast()
{
    updatePos();
    update();
}
