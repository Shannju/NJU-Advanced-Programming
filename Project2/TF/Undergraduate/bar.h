#ifndef BAR_H
#define BAR_H

#include "ui_bar.h"
#include<iostream>

#define enable_debug
#ifdef enable_debug
#define debug(s) {qDebug()<< s<<'\n';}
#else
#define debug(...){}
#endif

class Bar : public QWidget, private Ui::Bar
{
    Q_OBJECT
private:
    Ui::Bar* ui;
    const int length;
    int point[3];
public:
    explicit Bar(QWidget *parent = nullptr);
    void changePoint(int n,int i);
    void setPoint(int a,int b,int c);
    ~Bar();
};

#endif // BAR_H
