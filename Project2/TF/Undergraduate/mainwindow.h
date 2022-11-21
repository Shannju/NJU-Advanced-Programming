#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include<iostream>
#include"qpainter.h"
#include<QPaintEvent>
#include "scene.h"
#include<iostream>
#define enable_debug
#ifdef enable_debug
#define debug(s) {std::cerr<< s<<std::endl;}
#else
#define debug(...){}
#endif

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
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_released();
    void on_pushButton_4_released();
};
#endif // MAINWINDOW_H
