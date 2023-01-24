#ifndef SQUARE_H
#define SQUARE_H

#include <QLabel>
#include <QString>
#include<iostream>
#include"qpainter.h"
#include<QPaintEvent>
#include<iostream>
class Square : public QLabel
{
private:
    QString pic_name;
public:
    Square(QWidget *parent = nullptr);
    void setPic(QString name);
    void paintEvent(QPaintEvent*);
};

#endif // SQUARE_H
