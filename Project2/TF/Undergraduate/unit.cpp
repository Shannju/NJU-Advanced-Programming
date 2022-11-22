#include "unit.h"

Unit::Unit(QWidget *parent) :
    QWidget(parent)
{
    ui=new Ui::Unit;
    ui->setupUi(this);
}

