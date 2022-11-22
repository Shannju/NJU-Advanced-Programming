#include "bar.h"

Bar::Bar(QWidget *parent) :
    QWidget(parent)
{

    ui=new Ui::Bar;

    ui->setupUi(this);
ui->icon_life->setPic(":image/heart.png");
ui->icon_zhishi->setPic(":image/zhishi.png");
ui->icon_phi->setPic(":image/phi.png");
repaint();
}

Bar::~Bar()
{
    delete ui;
}
