#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStandardItemModel>
#include "ui_mainwidget.h"
#include <QStringList>
#include <QMessageBox>
#include <welcome.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void change();
    virtual void initUI();
    virtual void loadModel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_released();

protected:


private:

    QStandardItemModel* model;
    Ui::MainWidget *ui;



};
#endif // MAINWIDGET_H
