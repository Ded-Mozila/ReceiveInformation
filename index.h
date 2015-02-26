pragma one;
#include "header.h"

struct DataAll
{
	float Gg; // Стандартный градиент температуры
	float alpha // фактор снижения температуры
	float Rd; //Газовая постоянная для сухого воздуха
	//float Theta; // потенциальная температура
	float g;
	float Fs; // Поверхность геопотенциалла
	
}

class DataImage
{
	vector<vector< float > > ps;	// давление на уровне земли
	vector<vector< float > > ts;	
}
class Grid
{
	vector<vector< float > > hgt;
	vector<vector< float > > lat;
	vector<vector< float > > lon;
public:
	Grid(){};
	~Grid(){};
}