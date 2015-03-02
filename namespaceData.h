#ifndef NAMESPACEDATA_H
#define NAMESPACEDATA_H 
#include "header.h"
#include "file.h"
namespace Data_Lvl
{

	float g(9.80665);
	//vector<vector<float> > TableGeopotential(vector<vector<float> > ZMap); //Создание таблицы геопотенциала
	float Gg(6.5/1000); // Стандартный градиент температуры
	float Rd(287.04); //Газовая постоянная для сухого воздуха
	float SurfaceGeopotential(float); // Значение геопотенциала
	float TempReductionFactor(); // Фактор снижения температуры
	VVfloat TableGeopotential(VVfloat); //Создание таблицы геопотенциала
	float TempSurface(float,float,float);	//T* Нахождение температуры на уровне

	float alpha(Gg*Rd/g); // фактор снижения температур
	//string GenNameFile(const string,string);

	GidroFile hgt;		//Высота
	GidroFile lat;		//Широта
	GidroFile lon;		//Долгота
	VVfloat geopotential;
};

// string Data_Lvl::GenNameFile(const string dir,string fileName)
// {
// 	stringstream ss;
// 	ss << dir << fileName;
// 	string str;
// 	ss >> str;
// 	return str;
// };

float Data_Lvl::SurfaceGeopotential(float z)
{
 	return (g*z );
};
float Data_Lvl::TempReductionFactor()
{
	return (Gg*Rd/g);
};
float Data_Lvl::TempSurface(float Tnlev,float Ps,float Pnlev)
{
	return (Tnlev + (alpha * Tnlev)*( (Ps/Pnlev) -1 ));
};
VVfloat Data_Lvl::TableGeopotential(VVfloat ZMap)
{
	VVfloat Fs_p;
	vector<float> fs_p;
	int N = ZMap.size();
	int n = ZMap[0].size();// Возможна ошибка в размерноти массива
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			fs_p.push_back(SurfaceGeopotential(ZMap[i][j]));
		}
		Fs_p.push_back(fs_p);
		fs_p.clear();
	}
	return Fs_p;
};
#endif