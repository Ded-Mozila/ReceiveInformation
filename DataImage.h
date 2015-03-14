#ifndef DATA_IMAGE_H
#define DATA_IMAGE_H 
#include "file.h"
//#include "settings.h"
class DataImage
{
private:
	GidroFile ps;		// Давление на уровне земли
	GidroFile ts;		// Температура на уроввне земли
	VVfloat presureS;	// Давление на уровне моря!
	int hour; // час замера
public:
	DataImage(){};
	~DataImage(){};
	DataImage(const string,int); //Получение данных из файла с указанным именем
	GidroFile GetPs(void);
	GidroFile GetTs(void);
	int GetHour(void);							// Сколько часов
	string genName(int&,const string);			// Создание имени файла
	void Open(const string,int);				// Открытие файла
	DataImage& operator = (const DataImage&);	// Оператор присваивания
	void swap(DataImage&,DataImage&);			// Перег			 	урзка swap()
	DataImage(const DataImage&);				// Конструктор копирования
	void WriteFile(string,VVfloat);			 	// Запись в файл данных (сетки)
	void MapPmsl();								// Получение сетки давления на уровне моря
};
#endif