#ifndef SIGNUP_H
#define SIGNUP_H

#include "ui_signup.h"
#include "QRegularExpression"
#include "QRegularExpressionMatch"
#

class SignUp : public QWidget, private Ui::SignUp
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
private slots:
    void on_pushButton_released();
};

#endif // SIGNUP_H
