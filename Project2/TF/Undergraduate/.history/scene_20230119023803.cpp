#include "scene.h"
#include "graphscene.h"

Scene::Scene(QWidget *parent) :QWidget(parent),u(30),d(20),l(30),r(20),
    space(5),side(85)
{
    ui = new Ui::Scene;
    ui->setupUi(this);


    setFixedSize(1193,795);
    scene = new GraphScene;
    scene->init();
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

void Scene::mousePressEvent(QMouseEvent *event)
{
    if(currentBuf==nullptr)
          return;
      QPoint m_cell = this->getCell();
      if (event->button() == Qt::LeftButton)
      {
          for (int i = 0; i < plant.count(); i++)
          {
              if ((plant[i]->raw == m_cell.y()) && (plant[i]->column == m_cell.x()) && this->currentBuf->plantIndex > 0)
                  return;//如果放置的地方有植物了，那么无法放置
          }
          if ((m_cell.x() > -1) && (this->currentBuf != nullptr))
          {
              this->currentBuf->move(this->currentPos);
              this->putPlant(m_cell);
          }
      }
      else//点击右键放回植物
      {
          if (this->currentBuf != nullptr)
          {
              this->currentBuf->move(this->currentPos);
          }
          this->currentBuf = nullptr;
}}


void Scene::play()
{
    scene->newEnemy();
}




void Scene::on_pushButton_pressed()
{
     currentBuf=new tower(Color_list[6],-3,+5,-5,"专业课");
}

