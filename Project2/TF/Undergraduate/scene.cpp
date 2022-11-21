#include "scene.h"

Scene::Scene(QWidget *parent) :
    QWidget(parent)
{
    ui = new Ui::Scene;
    ui->setupUi(this);

}

