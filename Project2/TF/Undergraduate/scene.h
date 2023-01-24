#ifndef SCENE_H
#define SCENE_H

#include "ui_scene.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <Marcos.h>
#include <graphscene.h>
#include <QTimer>
#include <QMouseEvent>



class Scene : public QWidget, private Ui::Scene
{
    Q_OBJECT
private:
    Ui::Scene* ui;
    GraphScene *scene;
    Map m;
    QTimer * t0;
    QTimer * t1;
    int u,d,l,r;
    int space;
    int side;

public:
    explicit Scene(QWidget *parent = nullptr);
    void play();
    void closeEvent(QCloseEvent *);

private slots:
    void slotTimer();


};

#endif // SCENE_H
