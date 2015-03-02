#include "index.h"
#ifndef SETTINGS_H
#define SETTINGS_H 
class Settings
{
private:
	string nameFileSettings;
	vector<string> listNameFile;
	string GenNameFile(const string,string);
public:
	Settings(){};
	~Settings(){};
	Settings(string);
	vector<string> getList() const;
};
#endif