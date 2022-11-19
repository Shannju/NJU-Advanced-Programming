#ifndef ADMIN_H
#define ADMIN_H

#include "ui_admin.h"

class Admin : public QWidget, private Ui::Admin
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
};

#endif // ADMIN_H
