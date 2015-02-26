#ifndef INDEX_H
#define INDEX_H value

#include "header.h"
namespace data_lvl
{
	float SurfaceGeopotential(float z,float g); // Значение геопотенциала
	float TempReductionFactor(float Gg, float Rd, float g); // Фактор снижения температуры
	float Gg(6.5/1000); // Стандартный градиент температуры
	float Rd(287.04); //Газовая постоянная для сухого воздуха
	//float Theta; // потенциальная температура
	float g(9.80665);
	float alpha(TempReductionFactor(Gg,Rd,g)); // фактор снижения температур
	/** Для кадой точки свой)
	*float Fs; // Поверхность геопотенциалла
*/
	
};

class DataImage
{
	vector<vector< float > > ps;	// давление на уровне земли
	vector<vector< float > > ts;	
};
class Grid
{
	vector<vector< float > > hgt;
	vector<vector< float > > lat;
	vector<vector< float > > lon;
public:
	Grid(){};
	~Grid(){};
};
#endif