#include "index.h"
#include <cmath>
//#include "namespaceData.h"
////////////////////Class DataImage //////////////////////////////
DataImage::DataImage(const string strDir, int& H):hour(H)
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
