//#include "mainwidget.h"
#include "welcome.h"
#include <QApplication>
#include <QFile>
#include <QFont>
#include <file.h>
#include <structure.h>
int main(int argc, char *argv[])
{
//    File<User> fu;

    QApplication a(argc, argv);
    Welcome m;

    m.show();
    return a.exec();
}
