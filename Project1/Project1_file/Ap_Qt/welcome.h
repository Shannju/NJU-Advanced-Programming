#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QLabel>
#include "qpainter.h"
#include "qstyle.h"
#include "ui_welcome.h"
#include  "QStyleOption.h"
#include  "QMessageBox.h"
#include "mainwidget.h"

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
    void paintEvent(QPaintEvent *e);

private slots:
    void on_b_login_released();

    void on_pushButton_2_released();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
