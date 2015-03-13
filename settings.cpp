#include "settings.h"
#include "namespaceData.h"
Settings::Settings(string name): n(72), interval(3)
{
	if(freopen(name.c_str(),"r",stdin))
	{
		//string DirName;
		using namespace Data_Lvl;
		cin >> dirFile;//  Директория где расположены файлы
		cout << dirFile<<endl;
		hgt.OpenFile(GenNameFile(dirFile,"hgt.grd"));
		lat.OpenFile(GenNameFile(dirFile,"lat.grd"));
		lon.OpenFile(GenNameFile(dirFile,"lon.grd"));
		geopotential = TableGeopotential(hgt.setVector()); // Получение данных о геопотенциале
		fclose(stdin);
	}else
	{
		cout << "Not settings " <<  name << endl;
	}
}
int Settings::getN()
{
	return n;
}
int Settings::getIntarval()
{
	return interval;
}
int Settings::getIterval()
{
	return (n / interval)+1;
}
string Settings::getName()
{
	return dirFile;
}


