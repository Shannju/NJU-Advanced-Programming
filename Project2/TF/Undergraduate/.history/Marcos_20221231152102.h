#ifndef MARCOS_H
#define MARCOS_H

#include<iostream>



#define enable_debug
#ifdef enable_debug
#define debug(s) {std::cerr<< s<<std::endl;}
#else
#define debug(...){}
#endif

#define MAP_File ../__lc_time_data/map.txt

using namespace std;





#endif // MARCOS_H
