#include "mainwindow.h"
#include "qtimer.h"
#include "ui_mainwindow.h"
void MainWindow::setList()
{
    picList.append(":image/ss0.png");
    picList.append(":image/ss1.png");
    picList.append(":image/ss2.png");
    picList.append("");
    picList.append(":image/kk0.png");
    picList.append(":image/kk1.png");
    picList.append(":image/kk2.png");
    picList.append("");
    picList.append(":image/idol0.png");
    picList.append(":image/idol1.png");
    picList.append(":image/zy0.png");
    picList.append(":image/zy1.png");
    picList.append(":image/yst0.png");
    picList.append(":image/yst1.png");
    picList.append(":image/gf.png");
    picList.append(":image/ycf.png");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),counter(0)
{
    ui= new Ui::MainWindow;
    ui->setupUi(this);
    setFixedSize(1193,795);
    subWindow=nullptr;
    timer = new QTimer(this);
    setList();

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::timerDone));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerDone()
{
    int t = randomInt(1,3);
    while(t>0)
    {t--;
        int r = randomInt(0,picList.size()-1);
        switch (randomInt(0,2)) {
        case 0:
            ui->label_3->setPic(picList[r]);
            break;
        case 1:
            ui->label_4->setPic(picList[r]);
            break;
        case 2:
            ui->label_6->setPic(picList[r]);
            break;
        default:
            break;
        }
    }

    repaint();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":image/calendar.png");//图片的位置
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



