
#include "file.h"
#ifndef INDEX_H
#define INDEX_H 

class DataImage
{
	vector<vector<float> > ps;	// Давление на уровне земли
	vector<vector<float> > ts;	// Температура на уроввне земли
public:
	DataImage();
	~DataImage(){};

};
#endif