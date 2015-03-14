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
#include <dirent.h>
#include <errno.h>
#include <iomanip> // serfill() , setw()

#include <stdio.h> // freeopen()
//#include "namespaceData.h"
using namespace std;
//using namespace Data_Lvl;
typedef vector<vector<float> > VVfloat;
 // Создание строки имени  файла
string GenNameFile(const string,string);// file.cpp ->

#endif