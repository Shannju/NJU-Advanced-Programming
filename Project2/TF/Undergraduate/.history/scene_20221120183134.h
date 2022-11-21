#ifndef SCENE_H
#define SCENE_H

#include "ui_scene.h"
#include"QDebug"
class Scene : public QWidget, private Ui::Scene
{
    Q_OBJECT
private:
      Ui::Scene* ui;
public:
    explicit Scene(QWidget *parent = nullptr);
private slots:
      void on_pushButton_released();
};

#endif // SCENE_H
