#include "file.h"

#ifndef GIDRO_FILE_H
#define GIDRO_FILE_H 

class DataImage
{
private:
	GidroFile ps;	// Давление на уровне земли
	GidroFile ts;	// Температура на уроввне земли
	int hour; // час замера
public:
	DataImage(){};
	~DataImage(){};
	DataImage(const string,int&); //Получение данных из файла с указанным именем
	GidroFile GetPs();
	GidroFile GetTs();
	int GetHour();
	string genName(int&,const string);
	void Open(const string,int);
	DataImage& operator = (const DataImage&);
	void swap(DataImage&,DataImage&);
	DataImage(const DataImage&);

};
#endif