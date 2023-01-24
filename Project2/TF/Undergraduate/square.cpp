#include "square.h"

Square::Square(QWidget *parent)
{
    this->pic_name="";
    this->setBaseSize(std::min(height(),parent->height()),std::min(height(),parent->height()));
}

void Square::setPic(QString name)
{
    pic_name=name;
}

void Square::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(pic_name);//图片的位置
    painter.drawPixmap(0,0,height(),height(),pix);//根据窗口的高来将图片画在窗口上
}

