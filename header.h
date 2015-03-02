#ifndef HEADER_H
#define HEADER_H 

#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <iomanip> // serfill() , setw()

#include <stdio.h> // freeopen()
using namespace std;
typedef vector<vector<float> > VVfloat;
string GenNameFile(const string,string);// file.cpp ->
 // Создание строки имени  файла
#endif