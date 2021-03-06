#include "file.h"

GidroFile::GidroFile(string str): name(str)
{
	// open_file.open(str.c_str());
	OpenFile(str);
}
GidroFile::GidroFile(VVfloat bd):matrixMap(bd)
{
	minElement = 1000;
}
void GidroFile::OpenFile(string str)
{
	string strDDD;
	freopen(str.c_str(),"r",stdin);
	cin >> strDDD;
	cin >> row >> column;
	int i = 0,j = 0;
	cin >> i >> j;// Считывание размерности массива
	cin >> i >> j;// Считывание размерности массива
	cin >> minElement >> maxElement;
	vector<float> RowVector;
	for (i = 0; i < column; ++i)
	{
		for (j = 0; j < row; ++j)
		{
			float index = -1 ;
			cin >> index;
			RowVector.push_back(index);
		}
		matrixMap.push_back(RowVector);
		RowVector.clear();
	}
	fclose(stdin);
}
string GidroFile::setName(void)
{
	return name;
}
int GidroFile::setRow(void)
{
	return row;
}
int GidroFile::setColumn(void)
{
	return column;
}
float GidroFile::setMaxElement(void)
{
	return maxElement;
}
float GidroFile::setMinElement(void)
{
	return minElement;
}

GidroFile& GidroFile::operator= (const GidroFile& other)
{
	name = other.name;
	column = other.column;
	row = other.row;
	matrixMap = other.matrixMap;
	maxElement = other.maxElement;
	minElement = other.minElement;
	return *this;
}

VVfloat GidroFile::setVector()
{
	return matrixMap;
}

float GidroFile::At(int i, int j)
{
	return matrixMap[i][j];
}

long int GidroFile::sizeMap()
{
	return matrixMap.size();
}

long int GidroFile::sizeMap(int i)
{
	return matrixMap[i].size();
}