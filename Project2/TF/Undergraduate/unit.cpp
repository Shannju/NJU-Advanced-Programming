#include "unit.h"

void Unit::setPic(QString name)
{
    ui->icon->setPic(name);
}

Unit::Unit(QWidget *parent) :
    QWidget(parent)
{
    ui=new Ui::Unit;
    ui->setupUi(this);
}

