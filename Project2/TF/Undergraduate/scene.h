#ifndef SCENE_H
#define SCENE_H

#include "ui_scene.h"

class Scene : public QWidget, private Ui::Scene
{
    Q_OBJECT

public:
    explicit Scene(QWidget *parent = nullptr);
};

#endif // SCENE_H
