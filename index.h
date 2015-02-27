#ifndef INDEX_H
#define INDEX_H value

#include "header.h"
#include "file.h"
namespace data_lvl
{
	float g(9.80665);
	vector<vector<float> > TableGeopotential(vector<vector<float> > ZMap); //Создание таблицы геопотенциала
	float SurfaceGeopotential(float z); // Значение геопотенциала
	float TempReductionFactor(float Gg, float Rd, float g); // Фактор снижения температуры
	float TempSurface(float Tnlev,float Ps,float Pnlev);	//T* Нахождение температуры на уровне
	float Gg(6.5/1000); // Стандартный градиент температуры
	float Rd(287.04); //Газовая постоянная для сухого воздуха
	//float Theta; // потенциальная температура
	float alpha(TempReductionFactor(Gg,Rd,g)); // фактор снижения температур
	/** Для кадой точки свой)
	*float Fs; // Поверхность геопотенциалла
*/

};

class DataImage
{
	vector<vector<float> > ps;	// Давление на уровне земли
	vector<vector<float> > ts;	// Температура на уроввне земли
	vector<vector<float> > Fs;  // Геопотенцтал	
};
class Grid
{
	GidroFile hgt;
	GidroFile lat;
	GidroFile lon;
public:
	Grid(){};
	Grid(string,string,string);
	~Grid(){};
};
#endif