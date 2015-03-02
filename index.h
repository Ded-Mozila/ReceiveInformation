#include "file.h"

#ifndef INDEX_H
#define INDEX_H 

class DataImage
{
	GidroFile ps;	// Давление на уровне земли
	GidroFile ts;	// Температура на уроввне земли
	int hour; // час замера
public:
	DataImage(){};
	~DataImage(){};
	DataImage(const string,int&); //Получение данных из файла с указанным именем
	string genName(int&,const string);
};
#endif