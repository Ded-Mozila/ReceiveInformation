#include "DataImage.h"

////////////////////Class DataImage //////////////////////////////
DataImage::DataImage(const string strDir, int H):hour(H)
{
	Open(strDir,hour);
}
void DataImage::Open(const string strDir, int H)
{
	ps.OpenFile(GenNameFile(strDir,genName(H,"ps")));
	ts.OpenFile(GenNameFile(strDir,genName(H,"ts")));
	hgt.OpenFile(GenNameFile(strDir,"hgt.grd"));
}
void DataImage::Open(const string strDirPs,const string strDirTs,const string strDirHgt)
{
	ps.OpenFile(strDirPs);
	ts.OpenFile(strDirTs);
	hgt.OpenFile(strDirHgt);
}
string DataImage::genName(int h,const string str)
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

void DataImage::WriteFile(string str)
{
	ofstream file(str.c_str());
	int arrSize = presureS.size();
	file << "DSAA\n  " << arrSize << "  " << presureS[0].size() << endl \
		<<  " 1  " << arrSize << endl \
		<<  " 1  " << presureS[0].size() << endl \
		<<  " min   max \n";
	for (int i = 0; i < arrSize; ++i)
	{
		for (int j = 0; j < presureS[i].size(); ++j)
		{
			file << presureS[i][j] << "    ";
		}
		file << '\n';
	}
	file.close();
}

void DataImage::addHgt(GidroFile& file)
{
	hgt = file;
}

VVfloat DataImage::getPresure()
{
	return presureS;
}