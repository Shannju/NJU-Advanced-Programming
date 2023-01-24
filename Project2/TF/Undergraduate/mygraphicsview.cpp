#include "mygraphicsview.h"
#include <QMoveEvent>
#include <QDebug>

MYGraphicsView *MYGraphicsView::m_self = nullptr;

MYGraphicsView::MYGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    m_self = this;
}

MYGraphicsView::~MYGraphicsView()
{
    m_self = NULL;
}

void MYGraphicsView::mousePressEvent(QMouseEvent *event)
{
//    qDebug()<< "click!!!";
//       QList<QGraphicsItem *>l = items(event->pos());
//     qDebug() << "sizs:" << l.size();

//      for (auto i:l)
//          qDebug() <<i;
//    qDebug()<< "click end!!!";


    GraphScene* g =(GraphScene*) scene();
    if(event->buttons() == Qt::LeftButton){
        if (QGraphicsItem *item = itemAt(event->pos())) {
            qDebug() << "You clicked on item" << item;
            if (event->pos().y()<170&&item->zValue()==1)
            {
                Card* c =(Card*)item;
                if(g->currentCard)
                {
                    qDebug() << "You clicked again" << item;
                    return ;
                }
                g->currentCard=c;
                c->onSelected();
            }
            else if (g->currentCard){
                QList<QGraphicsItem *>itemList = items(event->pos());
                qDebug() << "You clicked on gezi list sizs:" << itemList.size();
                for (auto i:itemList)
                {
                    if (i->zValue()==1)
                    {
                        gezi* ge = (gezi* )i;
                        ge->onClick(g->currentCard);
                        g->currentCard->deSelcted();
                        g->currentCard= nullptr;
                        return;
                    }
                }
            }
        }
    }else{
        QList<QGraphicsItem *>itemList = items(event->pos());
        qDebug() << "You clicked right" ;
        for (auto i:itemList)
        {
            if (i->zValue()==1)
            {
                gezi* ge = (gezi* )i;
                ge->onClickright();

                return ;
            }
        }
    }



}

//void MYGraphicsView::mouseMoveEvent(QMouseEvent *event)
//{
//    static int j = 0;
//    if(event->buttons() == Qt::LeftButton)
//    {
//        QPoint point = event->pos();

//        emit mouseMovePoint(point);

//        //        cerr<<"mouseMoveEvent->send_signal" << "j: "<< j++ <<endl;
//    }

//    QGraphicsView::mouseMoveEvent(event);
//}


//void MYGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
//{
//    if (event->button()==Qt::LeftButton)
//    {
//        point=event->pos();      //QGraphicsView的坐标
//        emit mouseDoubleClick(point);   //发送信号
//    }
//    QGraphicsView::mouseDoubleClickEvent(event);
//}

