#include "timer.h"

void setTimer()
{
    timer = new QTimer();
      this->connect(timer,SIGNAL(timeout()),this,SLOT(timerDone()));

      timer->start( 1000 );  //一秒钟后开始触发，然后一秒一次

      timer->singleShot(2000,this,SLOT(slotTime()));      //2秒钟触发一次

}
