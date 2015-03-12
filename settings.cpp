#include "settings.h"
#include "namespaceData.h"
Settings::Settings(string name): nameFileSettings(name)
{
	freopen(name.c_str(),"r",stdin);
	string DirName;
	using namespace Data_Lvl;
	cin >> DirName;//  Директория где расположены файлы
	hgt.OpenFile(GenNameFile(DirName,"hgt.grd"));
	lat.OpenFile(GenNameFile(DirName,"lat.grd"));
	lon.OpenFile(GenNameFile(DirName,"lon.grd"));
	geopotential = TableGeopotential(hgt.setVector()); // Получение данных о геопотенциале
	fclose(stdin);
}
int Settings::getN()
{
	return n;
}
string Settings::getNameFile()
{
	return nameFileSettings;
}

