#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui= new Ui::MainWindow;
    ui->setupUi(this);
    setFixedSize(1005,670);
    subWindow=nullptr;

}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":image/calendar.PNG");//图片的位置
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//根据窗口的宽高来将图片画在窗口上
}





void MainWindow::on_pushButton_released()
{
    subWindow = new Scene();
    subWindow->show();
}


void MainWindow::on_pushButton_4_released()
{
    this->close();
}

