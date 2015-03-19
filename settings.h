#include "DataImage.h"

#ifndef SETTINGS_H
#define SETTINGS_H 
class Settings
{
private:
	string dirFile;					// Директория расположения файлов
	int n; 							// Количество временных отрезков
	int interval; 					// Интервал замерений
public:
	Settings(){};
	~Settings(){};
	int OpenSettings(string); 		// Открытие файла с настройками и считывание директории	
	Settings(string);
	int getN();
	int getIntarval();
	int getIterval();
	string getName();
};
#endif