#include "settings.h"
#include <sstream>
string Settings::GenNameFile(const string dir,string fileName)
{
	stringstream ss;
	ss << dir << fileName;
	string str;
	ss >> str;
	return str;
}
Settings::Settings(string name): nameFileSettings(name)
{
	freopen(name.c_str(),"r",stdin);
	string DirName;
	cin >> DirName;//  Директория где расположены файлы
	// data_lvl::hgt.OpenFile(GenNameFile(DirName,"hgt.grd"));
	// data_lvl::lat.OpenFile(GenNameFile(DirName,"lat.grd"));
	// data_lvl::lon.OpenFile(GenNameFile(DirName,"lon.grd"));
	fclose(stdin);
}

