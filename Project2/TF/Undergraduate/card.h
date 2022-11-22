#ifndef CARD_H
#define CARD_H

#include "ui_card.h"
#include <QString>
#include<QPaintEvent>
#include<iostream>

#define enable_debug
#ifdef enable_debug
#define debug(s) {qDebug()<< s<<'\n';}
#else
#define debug(...){}
#endif

class Card : public QWidget, private Ui::Card
{
    Q_OBJECT
private:
    QString pic_name;
public:
    Ui::Card * ui;

    explicit Card(QString pic_name,QWidget *parent = nullptr);
    explicit Card(QWidget *parent = nullptr);
       void paintEvent(QPaintEvent*);
void set_pic (QString pic_name);

};

#endif // CARD_H
