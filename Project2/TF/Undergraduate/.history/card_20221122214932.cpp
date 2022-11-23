#include "card.h"
#include "qpainter.h"

Card::Card(QWidget *parent) : QWidget(parent)
{
    this->pic_name=":image/ss0.png";
    ui = new Ui::Card;

    ui->setupUi(this);
    ui->mainWidget->setBaseSize(width(),height());
}


void Card::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(pic_name);//图片的位置
    painter.drawPixmap(0,0,this->height(),this->height(),pix);//根据窗口的高来将图片画在窗口上
}

void Card::set_pic(QString pic_name)
{
    this->pic_name=pic_name;
}

