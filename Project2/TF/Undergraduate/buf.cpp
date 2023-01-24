#include "buf.h"

buf::buf(const QString &name, QWidget *parent) : QPushButton(parent),
    name(name)
{}

//void buf::mousePressEvent(QMouseEvent *event)
//{
//    if(s->currentBuf==nullptr)
//        return;
//    QPoint m_cell = this->getCell();
//    if (event->button() == Qt::LeftButton)
//    {
//        for (int i = 0; i < plant.count(); i++)
//        {
//            if ((plant[i]->raw == m_cell.y()) && (plant[i]->column == m_cell.x()) && this->s->currentBuf->plantIndex > 0)
//                return;//如果放置的地方有植物了，那么无法放置
//        }
//        if ((m_cell.x() > -1) && (this->s->currentBuf != nullptr))
//        {
//            this->s->currentBuf->move(this->currentPos);
//            this->putPlant(m_cell);
//        }
//    }
//    else//点击右键放回植物
//    {
//        if (this->s->currentBuf != nullptr)
//        {
//            this->s->currentBuf->move(this->currentPos);
//        }
//        this->s->currentBuf = nullptr;
//    }
//}

buf::buf(QWidget *parent) : QPushButton(parent),
    name("")
{}
