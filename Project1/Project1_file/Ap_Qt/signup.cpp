#include "signup.h"


#include <QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void SignUp::on_pushButton_released()
{
    //check phonenum
    QRegularExpression rephnum ("[0-9]{1,21}");
    QRegularExpressionMatch m0=rephnum.match(phoneNumber->text());
    if(!m0.hasMatch())
    {
        QMessageBox::warning(this,tr("注册失败"),tr("联系方式无效，不超过20个字符，由数字组成"),QMessageBox::Ok);
        return ;
    }
    //check name
    QRegularExpression rename ("[a-zA-Z]{1,11}");
    QRegularExpressionMatch m1=rename.match(name->text());
    if(!m1.hasMatch())
    {
        QMessageBox::warning(this,tr("注册失败"),tr("用户名输入错误！不超过10个字符，英文字母"),QMessageBox::Ok);
        return ;
    }
    //check pass
    QRegularExpression repass ("[a-z0-9]{1,21}");
    QRegularExpressionMatch m=repass.match(password->text());
    if(!m.hasMatch())
    {
        QMessageBox::warning(this,tr("注册失败"),tr("密码不超过20个字符，只由小写字母和数字组成！"),QMessageBox::Ok);
        return ;
    }
    else if (password->text().compare(password1->text())!=0)
    {
        QMessageBox::warning(this,tr("注册失败"),tr("密码输入不相同"),QMessageBox::Ok);
        return ;
    }
    QMessageBox::information(this,tr("注册成功"),tr("点击返回登录"),QMessageBox::Close);
    this->close();
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

