#include "card.h"

Card::Card(QWidget *parent) :
    QWidget(parent)
{
      ui=new Ui::Card;
    ui->setupUi(this);
}
