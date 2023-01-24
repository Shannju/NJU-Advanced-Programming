#ifndef MARCOS_H
#define MARCOS_H

#include<iostream>
#include<cstring>
#include<qstring.h>
#include"random.h"
#include <QMouseEvent>

#define enable_debug
#ifdef enable_debug
#define Debug(s) {std::cerr<< s<<std::endl;}
#else
#define Debug(...){}
#endif

using namespace std;


const string FULL_Path ="D:\\Data\\Advanced Programming\\NJU-Advanced-Programming\\Project2\\TF\\Undergraduate";

const string MAP_File = FULL_Path +"\\data\\map1.txt";

const vector <QString> Color_list={":/image/empty.png",":/image/s_white.png",":/image/s_white.png",":/image/s_white.png",":/image/s_white.png",":/image/s_white.png",":/image/s_white.png",":/image/s_yel.png",":/image/s_pink.png",":/image/s_blue.png",":/image/s_green.png",":/image/s_red.png"};
const vector <QString> Enemy_list={":/image/ss0.png",":/image/kk0.png",":/image/zy0.png",":/image/yst0.png",":/image/idol0.png"};

const vector <pair<int,int>> Dir_list={pair(0,0),pair(0,-1),pair(0,1),pair(-1,0),pair(1,0),pair(1,0),pair(0,0)};

#endif // MARCOS_H
