#include "rand.h"

string getTime() //获取本地时间
{
  time_t timep;
  time(&timep);
  char tmp[64];
  struct tm nowTime;
  localtime_s(&nowTime, &timep);
  strftime(tmp, sizeof(tmp), "%Y-%m-%d", &nowTime);
  return string(tmp);
}

string getTime_0() //获取本地时间
{
  time_t timep;
  time(&timep);
  char tmp[64];
  struct tm nowTime;
  localtime_s(&nowTime, &timep);
  strftime(tmp, sizeof(tmp), "%H:%M:%S", &nowTime);
  return string(tmp);
}

time_t getTime_value() //获取本地时间
{
  time_t timep;
  time(&timep);
  return timep;
}

int Setid() //随机数生成id
{
  srand(time(0));
  int num = rand();
  return num % 1000;
}

string new_id()
{
  int n = Setid();
  string new_id = to_string(n);
  int s = new_id.size();
  if (s < 3)
  {
    for (int i = 0; i < 3 - s; i++)
      new_id.insert(0, "0");
  }
  return new_id;
}
