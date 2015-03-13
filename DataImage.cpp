#include "DataImage.h"
#include <cmath>
//#include "namespaceData.h"
////////////////////Class DataImage //////////////////////////////
DataImage::DataImage(const string strDir, int H):hour(H)
{
	Open(strDir,hour);
}
void DataImage::Open(const string strDir, int H)
{
	ps.OpenFile(GenNameFile(strDir,genName(H,"ps")));
	ts.OpenFile(GenNameFile(strDir,genName(H,"ts")));
}
string DataImage::genName(int& h,const string str)
{
	stringstream ss;
	ss << str << '_'<< setfill ('0') << setw (3) << h << ".grd";
	string fileName;
	ss >> fileName;
	return fileName;
}
DataImage& DataImage::operator= (const DataImage& other)
{
	ps = other.ps;
	ts = other.ts;
	hour = other.hour;
	return *this;

}
int DataImage::GetHour()
{
	return hour;
}
GidroFile DataImage::GetTs()
{
	return ts;
}

GidroFile DataImage::GetPs()
{
	return ps;
}

DataImage::DataImage(const DataImage& other):hour(other.hour),ps(other.ps),ts(other.ts)
{}

void DataImage::WriteFile(string str, VVfloat arr)
{

	freopen(str.c_str(),"w",stdout);
	int arrSize = arr.size();
	for (int i = 0; i < arrSize; ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			cout << arr[i][j] << "    ";
		}
		cout << endl;
	}
	fclose(stdout);

}
