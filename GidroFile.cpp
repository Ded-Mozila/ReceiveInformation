#include "file.h"

GidroFile::GidroFile(string str): name(str)
{
	// open_file.open(str.c_str());
	OpenFile(str);
}
void GidroFile::FindData()
{
	
}

void GidroFile::OpenFile(string str)
{
	freopen(str.c_str(),"r",stdin);
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