#ifndef NAMESPACEDATA_H
#define NAMESPACEDATA_H 
#include "header.h"
#include "file.h"
namespace Data_Lvl
{

	float g(9.80665);
	//vector<vector<float> > TableGeopotential(vector<vector<float> > ZMap); //Создание таблицы геопотенциала
	float Gg(6.5/1000); 					// Стандартный градиент температуры
	float Rd(287.04);						// Газовая постоянная для сухого воздуха
	float SurfaceGeopotential(float); 		// Значение геопотенциала
	float TempReductionFactor(); 			// Фактор снижения температуры
	VVfloat TableGeopotential(VVfloat); 	// Создание таблицы геопотенциала
	float TempSurface(float,float,float);	// T* Нахождение температуры на уровне

	float alpha(Gg*Rd/g); 					// фактор снижения температур
	GidroFile hgt;							// Высота
	GidroFile lat;							// Широта
	GidroFile lon;							// Долгота
	VVfloat geopotential;					// Геопотенциал
	float Pmsl(float,float,float);			// Функция нахождения давлений на уровне земли
	VVfloat  HorizontalInterpolation(VVfloat);	//Горизонтальная интерполяция

};

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
	// VVfloat Fs_p;
	// vector<float> fs_p;
	// int N = ZMap.size();
	// int n = ZMap[0].size();// Возможна ошибка в размерноти массива
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < n ; ++j)
	// 	{
	// 		fs_p.push_back(SurfaceGeopotential(ZMap[i][j]));
	// 	}
	// 	Fs_p.push_back(fs_p);
	// 	fs_p.clear();
	// }
	return ZMap;
};
float Data_Lvl::Pmsl(float ps, float T, float F)
{
	F = F*g;
	return (ps*exp((F/(Rd*T))*( 1 - (alpha*F)/(2*Rd*T) + (1/3)*((alpha*F)/(2*Rd*T)))));
}
VVfloat Data_Lvl::HorizontalInterpolation(VVfloat pi,VVfloat &p)
{
	VVfloat new_pi(pi);	//n+1 - итерация метода Гаусса-Зейделя
	int n = pi.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < nn; ++j)
		{
			//Учесть граничные случаи для которых некоторых элементов не существует!!!!!
			new_pi[i][j] = 0.25*(new_pi[i-1][j] + pi[i+1][j] + new_pi[i][j-1] + pi[i][j+1]  - (p[i-1][j] + p[i+1][j] + p[i][j-1] + p[i][j+1] - 4*p[i][j]));
		}
	}
	return new_pi;
}
#endif