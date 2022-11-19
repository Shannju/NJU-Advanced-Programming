#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{




}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget:: initUI(){
    ui->setupUi(this);
}
void MainWidget:: loadModel(){
    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->table->setModel(model);   //将table设置成model这个标准条目模型的模板, model设置的内容都将显示在table上

    this->model->setHorizontalHeaderLabels(QStringList()<< "商品ID"<< "名称"<<"价格"<<"上架时间"<< "商品状态");
    this->ui->table->setColumnWidth(0, 100);    //设置列的宽度
    this->ui->table->setColumnWidth(1, 150);
    this->ui->table->setColumnWidth(2, 50);
    this->ui->table->setColumnWidth(3, 50);
    this->ui->table->setColumnWidth(4, 100);
    this->ui->table->setColumnWidth(5, 150);

    /*setItem设置条目栏中的一个格子的信息*/
    this->model->setItem(1, 5, new QStandardItem("hello world" ) );

    /*设置行字段名*/
    model->setRowCount(3);
    model->setHeaderData(0,Qt::Vertical, "行0");
    model->setHeaderData(1,Qt::Vertical, "行1");
    model->setHeaderData(2,Qt::Vertical, "行2");}

void MainWidget::  change(){

}

void MainWidget::on_pushButton_clicked()
{

}


void MainWidget::on_pushButton_7_released()//右上 注销
{
    int ret = QMessageBox::question(this,tr("退出登录"),tr("您确认要退出吗"));
    if (ret==QMessageBox::Yes)

    {
        this->close();
        Welcome * w0 = new Welcome;


        w0->show();
    }

}

