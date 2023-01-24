#ifndef MARCOS_H
#define MARCOS_H

#include<iostream>



#define enable_debug
#ifdef enable_debug
#define debug(s) {std::cerr<< s<<std::endl;}
#else
#define debug(...){}
#endif

#define MAP_File map.txt

using namespace std;





#endif // MARCOS_H
