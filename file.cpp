#include "file.h"


string GenNameFile(const string dir,string fileName) // -> header.h
{
	stringstream ss;
	ss << dir << fileName;
	string str;
	ss >> str;
	return str;
};
string GetStringInt(int i)// -> header.h
{
	string str;
	stringstream ss;
	ss <<  setfill ('0')\
	<< setw (2) << i;
	ss >> str;
	return str;
}

bool mkdirp(const char* path, mode_t mode) //Создание дерева директории
{
	// const cast for hack
	char* p = const_cast<char*>(path);
	// Do mkdir for each slash until end of string or error
	while (*p != '\0') 
	{
		// Skip first character
		p++;
		// Find first slash or end
		while(*p != '\0' && *p != '/') p++;

		// Remember value from p
		char v = *p;

		// Write end of string at p
		*p = '\0';

		// Create folder from path to '\0' inserted at p
		if(mkdir(path, mode) == -1 && errno != EEXIST) 
		{
			*p = v;
			return false;
		}
		// Restore path to it's former glory
		*p = v;
	}
	return true;
}
// File::File(){};
// File::~File(){};
File::File(string Name):name(Name)
{
	open_file.open(name.c_str(),ios_base::in);	
}

fstream* File::getSingnFile(void)
{
	return &open_file;
}
string  File::getNameFile(void)
{
	return name;
}

ListDir::ListDir(string Dir):name(Dir)
{
	listNameFile = vector<string>();
	getdir();
	printDirList();
}
int ListDir::getdir(void)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(name.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << name << endl;
		return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {
		listNameFile.push_back(string(dirp->d_name));
	}
	closedir(dp);
	sort (listNameFile.begin(), listNameFile.end());
	return 0;
}

void printElementList(string nameFile)
{
	cout << nameFile << endl;
}

void ListDir::printDirList(void)
{
	for_each(listNameFile.begin(), listNameFile.end(), printElementList);
}