#ifndef SCENE_H
#define SCENE_H

#include "ui_scene.h"
#include<iostream>
#define enable_debug
#ifdef enable_debug
#define debug(s) {std::cerr<< s<<std::endl;}
#else
#define debug(...){}
#endif

class Scene : public QWidget, private Ui::Scene
{
    Q_OBJECT
private:
      Ui::Scene* ui;
public:
    explicit Scene(QWidget *parent = nullptr);

};

#endif // SCENE_H
