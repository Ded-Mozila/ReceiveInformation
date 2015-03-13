#include "file.h"

GidroFile::GidroFile(string str): name(str)
{
	// open_file.open(str.c_str());
	OpenFile(str);
}


void GidroFile::OpenFile(string str)
{
	if(freopen(str.c_str(),"r",stdin))
	{	
		string index;
		cin >> index;
		cin >> row >> column;
		int i = 0,j = 0;
		cin >> i >> j;// Считывание размерности массива
		cin >> i >> j;// Считывание размерности массива
		cin >> minElement >> maxElement;
		vector<float> RowVector;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < column; ++j)
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
	else{
		cout << "File! " << str.c_str()<< endl;
	}
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
