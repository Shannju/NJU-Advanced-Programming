#include "mainwindow.h"
#include "qgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui= new Ui::MainWindow;
    ui->setupUi(this);
    QGraphicsScene *graphic = new QGraphicsScene(this);
//    graphic->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
}

