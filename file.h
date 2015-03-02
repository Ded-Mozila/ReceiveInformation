#include "header.h"
#ifndef FILE_H
#define FILE_H
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
	void openFile();
};

class GidroFile:  public File
{
private:
	string name;
	int column;
	int row;
	float maxElement;
	float minElement;
	VVfloat matrixMap;
	void FindData();
public:
	GidroFile(){};
	GidroFile(string);
	void OpenFile(string);
	VVfloat setVector();
	~GidroFile(){};
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


#endif