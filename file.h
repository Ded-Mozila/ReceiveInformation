#pragma one
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
using namespace std;

class File
{
private:
	string name;
	fstream open_file;
public:
	File(){};
	File(string);	
	virtual ~File(){
		open_file.close();
	};
	//void setNameFile(string& Name){name = Name;};//Замена имени файла
	//void setSignFile(fstream& SFile){open_file =SFile}; // Замена указателя на файл
	fstream* getSingnFile(void); // Получение указателя на файл
	string getNameFile(void);
};

class GidroFile:  public File
{
private:
	int column;
	int row;
	float maxElement;
	float minElement;
	vector<vector<int> > matrixMap;
public:
	GidroFile();
	GidroFile(string);
//	void 


};
class ListDir
{
private:
	string name;
	vector<string> listNameFile;
public:
	ListDir(){};
	ListDir(string);
	~ListDir(){};
	//void printElementList(string nameFile); непонятно почему не работает!
	void printDirList(void);
	int getdir(void);

};