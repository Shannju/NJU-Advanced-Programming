#ifndef UNIT_H
#define UNIT_H

#include "ui_unit.h"

class Unit : public QWidget, private Ui::Unit
{
    Q_OBJECT
private:
      Ui::Unit * ui;
public:
    explicit Unit(QWidget *parent = nullptr);
};

#endif // UNIT_H
