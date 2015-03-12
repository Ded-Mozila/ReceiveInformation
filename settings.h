#include "GidroFile.h"

#ifndef SETTINGS_H
#define SETTINGS_H 
class Settings
{
private:
	string FileSettings;
	vector<string> listNameFile;
	int n; // Количество временных отрезков
public:
	Settings(){};
	~Settings(){};
	Settings(string);
	int getN();
	string getName();
};
#endif