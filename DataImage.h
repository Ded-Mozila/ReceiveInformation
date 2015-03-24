#ifndef DATA_IMAGE_H
#define DATA_IMAGE_H 
#include "file.h"
//#include "settings.h"
class DataImage
{
private:
	GidroFile ps;							// Давление на уровне земли
	GidroFile ts;							// Температура на уроввне земли
	VVfloat presureS;						// Давление на уровне моря!
	vector<VVfloat> gif;					// Все изменения за 20 итераций
	GidroFile hgt;							// Высота
	GidroFile lat;							// Широта
	GidroFile lon;							// Долгота
	VVfloat geopotential;					// Геопотенциал
	int hour; // час замера
public:
	DataImage(){};
	~DataImage(){};
	DataImage(const string,int); //Получение данных из файла с указанным именем
	GidroFile GetPs(void);
	GidroFile GetTs(void);
	int GetHour(void);							// Сколько часов
	string genName(int,const string);			// Создание имени файла
	void Open(const string,int);				// Открытие файла
	DataImage& operator = (const DataImage&);	// Оператор присваивания
	void swap(DataImage&,DataImage&);			// Перег			 	урзка swap()
	DataImage(const DataImage&);				// Конструктор копирования
	void WriteFile(string);			 			// Запись в файл данных (сетки)
	void MapPmsl();	//-> settings.cpp			// Получение сетки давления на уровне моря
	void HorizontalInterpolation_gif();			//-> settings.cpp	Горизонтальная интерполяция
	void addHgt(GidroFile&);
};
#endif