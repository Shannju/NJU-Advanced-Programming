#ifndef TOP_H
#define TOP_H

#include "ui_top.h"

class Top : public QWidget, private Ui::Top
{
    Q_OBJECT

public:
    explicit Top(QWidget *parent = nullptr);
};

#endif // TOP_H
