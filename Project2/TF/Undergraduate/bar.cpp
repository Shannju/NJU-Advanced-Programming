#include "bar.h"

Bar::Bar(QWidget *parent) :
    QWidget(parent),length(586)
{

    ui=new Ui::Bar;
    ui->setupUi(this);
ui->icon_life->setPic(":image/heart.png");
ui->icon_zhishi->setPic(":image/zhishi.png");
ui->icon_phi->setPic(":image/phi.png");
repaint();
}

void Bar::changePoint(int n, int i)
{
point[i]=n;
switch (i) {
case 0:
    ui->bar_life->setFixedWidth((n*length/100));
    break;
case 1:
    ui->bar_zhishi->setFixedWidth((n*length/100));
    break;
case 2:
    ui->bar_phi->setFixedWidth((n*length/100));
    break;
default:
    break;
}
repaint();
}

void Bar::setPoint(int a, int b, int c)
{
point[0]=a;
point[1]=b;
point[2]=c;
for (int i =0;i<3;i++)
    changePoint(point[i],i);
}




Bar::~Bar()
{
    delete ui;
}
