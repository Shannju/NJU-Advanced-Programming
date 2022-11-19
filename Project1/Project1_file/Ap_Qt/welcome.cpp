#include "welcome.h"
#include "signup.h"
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Welcome::on_b_login_released()
{
    MainWidget *h=new MainWidget;
    h->initUI();
    h->show();
    //    if(ui->username->text() == "admin" && ui->password->text() == "123456"){
    //        this->close();
    //        MainWidget *h=new MainWidget;
    //        h->show();
    //    }else{
    //        QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码输入错误！"),QMessageBox::Ok);
    //        ui->username->clear();
    //        ui->password->clear();
    //        ui->username->setFocus();
    //    }

}


void Welcome::on_pushButton_2_released()
{
       this->close();
    SignUp* sup= new SignUp;
    sup->show();

}

