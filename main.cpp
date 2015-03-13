
#include "settings.h"
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
	for (int i = 0; i < map.getIterval(); ++i)
	{
		DataImage newIMG(map.getName().c_str(),i*3);
		
		//newIMG.WriteFile
		img.push_back(newIMG);
	}
	return 0;
}