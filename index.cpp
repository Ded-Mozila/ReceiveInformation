#include "index.h"

float data_lvl::SurfaceGeopotential(float z)
{
	return g*z ;
}
float data_lvl::TempReductionFactor(float Gg, float Rd, float g)
{
	return Gg*Rd/g;
}

float data_lvl::TempSurface(float Tnlev,float Ps,float Pnlev)
{
	return (Tnlev + (alpha * Tnlev)*( (Ps/Pnlev) -1 ));
}

vector<vector<float> > data_lvl::TableGeopotential(vector<vector<float> > ZMap)
{
	vector<vector<float> > Fs;
	vector<float> fs;
	int N = ZMap.size();
	int n = ZMap[0].size();// Возможна ошибка в размерноти массива
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			fs.push_back(SurfaceGeopotential(ZMap[i][j]));
		}
		Fs.push_back(fs);
		fs.clear();
	}
}


//////////////////////Class Grid /////////////////////////////////

Grid::Grid(string FN_hgt, string FD_lat, string FD_lon)
{
	
}