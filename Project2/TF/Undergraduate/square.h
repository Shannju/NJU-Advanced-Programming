#ifndef SQUARE_H
#define SQUARE_H

#include <QLabel>

#include<iostream>
#include"qpainter.h"
#include<QPaintEvent>
#include <QString>
#define enable_debug
#ifdef enable_debug
#define debug(s) {std::cerr<< s<<std::endl;}
#else
#define debug(...){}
#endif
class Square : public QLabel
{
private:
    QString pic_name;
public:
    Square(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);
};

#endif // SQUARE_H
