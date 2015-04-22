#ifndef HEADER_H
#define HEADER_H 

#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <iomanip> // serfill() , setw()
#include <cmath>
#include <cstdlib> // itoa()
#include <stdio.h> // freeopen()
//#include "namespaceData.h"
using namespace std;
//using namespace Data_Lvl;
typedef vector<vector<float> > VVfloat;
 // Создание строки имени  файла
string GenNameFile(const string,string);// file.cpp ->
string GetStringInt(int);// file.cpp ->
bool mkdirp(const char* path, mode_t mode);// file.cpp ->
VVfloat HInterpolation(VVfloat,VVfloat);
VVfloat Smth9(VVfloat);// file.cpp ->
float PointIner(int,int,VVfloat,int,int);// file.cpp ->

#endif