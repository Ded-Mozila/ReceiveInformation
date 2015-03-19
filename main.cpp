#include "DataImage.h"
#include "settings.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	// string name ("/home/aleks/Aleksander/study/Credential/sasha_diplom_data/2013.12.11");
	// ListDir Dir(name);
	//string nameDir("/home/aleks/Aleksander/study/Credential/sasha_diplom_data/2013.12.11/");

	// GidroFile A("/home/aleks/Aleksander/study/Credential/sasha_diplom_data/2013.12.11/ps_000.grd");
	
	/*
		Тест class Settings
	*/
	Settings map("/home/aleks/Aleksander/study/Credential/Project/ReceiveInformation_1/settings.txt");
	vector<DataImage> img/*(map.getN());*/; // Все картинки
	for (int i = 0; i < map.getN()+1; i=i+3)
	{
		cout << "Open file: ps_" << i << endl;
		DataImage newIMG(map.getName().c_str(),i);
		cout << "Good Open file: ps_" << i << endl;
		newIMG.MapPmsl();
		cout << "Good MapPmsl file: ps_" << i << endl;
		string str(GenNameFile(GenNameFile("FILE/presure_",GetStringInt(i)),".txt"));
		cout << str << endl;
		newIMG.WriteFile(str);		
		//img.push_back(newIMG);
		cout << "Good make file: presure_" << i<< endl;
	}
	return 0;
}