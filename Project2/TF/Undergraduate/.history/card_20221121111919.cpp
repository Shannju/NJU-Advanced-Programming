#include "card.h"

Card::Card(QWidget *parent) :
    QWidget(parent)
{
      ui=new Ui::Unit;
    ui->setupUi(this);
}
