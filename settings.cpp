#include "settings.h"
#include "namespaceData.h"
using namespace Data_Lvl;
Settings::Settings(string name): n(72), interval(3)
{
		OpenSettings(name); // Проблема в этой программе
		// hgt.OpenFile(GenNameFile(dirFile,"hgt.grd"));
		// lat.OpenFile(GenNameFile(dirFile,"lat.grd"));
		// lon.OpenFile(GenNameFile(dirFile,"lon.grd"));
		// geopotential = TableGeopotential(hgt.setVector()); // Получение данных о геопотенциале
}
int  Settings::OpenSettings(string str)
{
	freopen(str.c_str(),"r",stdin);
	cin >> dirFile;//  Директория где расположены файлы
	int N(0);
	cin >> N;		// количество 
	dirList.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> dirList[i];
	}
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
string Settings::getNameDir()
{
	return dirFile;
}

string Settings::getName(int i)
{
	return dirList[i];
}

int Settings::getListSize()
{
	return dirList.size();
}

string Settings::getNameMakeDir(int i)
{
	if (!dirList.empty())
	{
		unsigned last = dirList[i].find_last_of("/\\");
		string str(dirList[i].substr(0,last));
		unsigned first =str.find_last_of("/\\");
		//return GenNameFile(dirFile,dirList[i].substr(first+1));
		return dirList[i].substr(first+1);
	}
	return "0";
}
void Settings::printInFile(string str,GidroFile grd)
{
	ofstream file_grd(str.c_str());
	file_grd << "DSAA\n  " << grd.sizeMap() << "  " << grd.sizeMap(0) << endl \
		<<  " 1  " << grd.sizeMap() << endl \
		<<  " 1  " << grd.sizeMap(0)<< endl \
		<<  " min  "<< grd.setMinElement()<<" \n";
	for (int i = 0; i < grd.sizeMap(); ++i)
	{
		for (int j = 0; j < grd.sizeMap(i); ++j)
		{
			file_grd << grd.At(i,j)<< "    ";
		}
		file_grd << '\n';
	}
	file_grd.close();
}
void Settings::printLatLon(const string dir, const string str)
{
	GidroFile lat(GenNameFile(dir,"lat.grd"));
	GidroFile lon(GenNameFile(dir,"lon.grd"));
	printInFile(GenNameFile(str,"lat.grd"),lat);
	printInFile(GenNameFile(str,"lon.grd"),lon);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void DataImage::MapPmsl()
{
	// using namespace Data_Lvl;
	int psSize = ps.sizeMap();
	for (int i = 0; i < psSize; ++i)
	{
		vector<float> newString;
		for (int j = 0; j < ps.sizeMap(i); ++j)
		{
			newString.push_back(Pmsl(ps.At(i,j),ts.At(i,j),geopotential[i][j]));
		}
		presureS.push_back(newString);
		//newString.clear();
	}
}

void DataImage::HorizontalInterpolation_gif()
{
	vector<VVfloat> gif(20);
	gif[0] = presureS;
	VVfloat p(ps.setVector());
	for (int i = 1; i < gif.size(); ++i)
	{
		gif[i] = Interpolation(gif[i-1],p);
	}
	presureS = gif[1];
}

void DataImage::HorizontalInterpolation_gif(VVfloat P)
{
	// void<float> row(500, 1000.0); 
	// VVfloat Pi(400,row);
	// VVfloat p(ps.setVector());
	// for (int i = 1; i < gif.size(); ++i)
	// {
	// 	gif[i] = Interpolation(gif[i-1],p);
	// 	cout << i << endl;
	// }
	// presureS = gif[1];
}
VVfloat HInterpolation(VVfloat pi, VVfloat p)
{
	return Interpolation(pi,p);
}