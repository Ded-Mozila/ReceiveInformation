#include "settings.h"
#include "namespaceData.h"
Settings::Settings(string name): n(72), interval(3)
{
		//OpenSettings(name); // Проблема в этой программе
		using namespace Data_Lvl;
		dirFile = "/home/aleks/Aleksander/study/Credential/sasha_diplom_data/2013.12.11/";
		hgt.OpenFile(GenNameFile(dirFile,"hgt.grd"));
		lat.OpenFile(GenNameFile(dirFile,"lat.grd"));
		lon.OpenFile(GenNameFile(dirFile,"lon.grd"));
		geopotential = TableGeopotential(hgt.setVector()); // Получение данных о геопотенциале
}
int  Settings::OpenSettings(string str)
{
	freopen(str.c_str(),"r",stdin);
	cin >> dirFile;//  Директория где расположены файлы
	fclose(stdin);
	return 0;
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
void DataImage::MapPmsl()
{
	using namespace Data_Lvl;
	int psSize = ps.sizeMap();
	for (int i = 0; i < psSize; ++i)
	{
		vector<float> newString;
		for (int j = 0; j < ps.sizeMap(i); ++j)
		{
			newString.push_back(Pmsl(ps.At(i,j),ts.At(i,j),hgt.At(i,j)));
		}
		presureS.push_back(newString);
		//newString.clear();
	}
}