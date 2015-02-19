#include "file.h"

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
