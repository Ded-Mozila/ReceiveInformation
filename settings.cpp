#include "settings.h"
#include "namespaceData.h"
Settings::Settings(string name): n(72), interval(3)
{
	// if(freopen(name.c_str(),"r",stdin))
	// {
		freopen(name.c_str(),"r",stdin);
		//string DirName;
		using namespace Data_Lvl;
		cin >> dirFile;//  Директория где расположены файлы
		hgt.OpenFile(GenNameFile(dirFile,"hgt.grd"));
		lat.OpenFile(GenNameFile(dirFile,"lat.grd"));
		lon.OpenFile(GenNameFile(dirFile,"lon.grd"));
		geopotential = TableGeopotential(hgt.setVector()); // Получение данных о геопотенциале
		fclose(stdin);
	// }else
	// {
	// 	cout << "Not settings " <<  name << endl;
	// }
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
	cout << psSize << " \n";
	vector<float> newString;
	for (int i = 0; i < psSize; ++i)
	{
		for (int j = 0; j < ps.sizeMap(i); ++j)
		{
			newString.push_back(Pmsl(ps.At(i,j),ts.At(i,j),hgt.At(i,j)));
		}
		presureS.push_back(newString);
		newString.clear();
	}
}