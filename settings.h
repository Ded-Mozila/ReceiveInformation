#include "DataImage.h"

#ifndef SETTINGS_H
#define SETTINGS_H 
class Settings
{
private:
	string dirFile;					// Директория расположения выходных файлов 
	vector<string> dirList;			// Директории расположения файлов
	int n; 							// Количество временных отрезков
	int interval; 					// Интервал замерений
public:
	Settings(){};
	~Settings(){};
	int OpenSettings(string); 		// Открытие файла с настройками и считывание директории	
	Settings(string);
	int getN();						// Количество интервалов временных
	int getListSize();				// Размерность массива директорий
	int getIntarval();
	int getIterval();
	string getNameDir();								// -> dirFile
	string getName(int);								// -> dirList[i]
	string getNameMakeDir(int i);						// Возвращение название папки для хранения информации	
	void printLatLon(const string,const string);		// copy file lan.grd, lon.grd in dir string
	void printInFile(string, GidroFile);
};
#endif