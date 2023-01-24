#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    //    Scene w;
    //    w.play();
    //    w.show();

    return a.exec();
}
