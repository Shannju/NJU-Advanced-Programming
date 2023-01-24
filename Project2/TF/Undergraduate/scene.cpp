#include "scene.h"
#include "graphscene.h"

Scene::Scene(QWidget *parent) :QWidget(parent),u(30),d(20),l(30),r(20),
    space(5),side(85)
{
    ui = new Ui::Scene;
    ui->setupUi(this);


    setFixedSize(1193,795);
    scene = new GraphScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setCursor(Qt::CrossCursor);   //设置鼠标
    ui->graphicsView->setMouseTracking(true);


    t0 = new QTimer(this);
    t0->start(1000/24);
    QObject :: connect(t0,SIGNAL(timeout()),scene,SLOT(advance()));
    QObject :: connect(t0,SIGNAL(timeout()),this,SLOT(slotTimer()));

}

void Scene::slotTimer()
{
    if (randomBool(500))
        scene->newEnemy();
}



void Scene::play()
{
    scene->newEnemy();

}

void Scene::closeEvent(QCloseEvent *)
{
       scene-> ms();
}


