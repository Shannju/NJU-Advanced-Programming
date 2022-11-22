#include "card.h"

Card::Card(QString pic_name,QWidget *parent) : QWidget(parent),pic_name(pic_name)
{
    ui = new Ui::Card;
    ui->setupUi(this);
}

void Card::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(pic_name);//图片的位置
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//根据窗口的宽高来将图片画在窗口上
}

