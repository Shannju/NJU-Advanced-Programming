#ifndef CARD_H
#define CARD_H

#include "ui_card.h"

class Card : public QWidget, private Ui::Card
{
    Q_OBJECT
private:
   Ui::Card * ui;
public:
    explicit Card(QWidget *parent = nullptr);
};

#endif // CARD_H
