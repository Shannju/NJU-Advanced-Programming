#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include<iostream>
#include"qpainter.h"
#include<QPaintEvent>
#include "scene.h"
#include<iostream>
#include<time.h>
#include<QVector>
#include<random.h>
#include<QTimerEvent>
#include<QFileDialog>


namespace Ui
{
class MainWindow;
}
class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    Scene* subWindow;
    QTimer *timer;
    int counter;
    QVector<QString> picList;
    void setList();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerDone();
protected:
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_released();
    void on_pushButton_4_released();
};

#endif // MAINWINDOW_H
