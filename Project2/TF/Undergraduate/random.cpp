#include"random.h"

int randomInt(int a, int b)
{

    QTime randtime;
    randtime = QTime::currentTime();
    srand(randtime.msec()+randtime.second()*1000); //以当前时间ms为随机种子

 return rand() % (b - a + 1) + a;
}
