#include "DataImage.h"
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
	for (int i = 0; i < map.getN()+1; i=i+3)
	{
		DataImage newIMG(map.getName().c_str(),i);
		newIMG.MapPmsl();
	// cout << GenNameFile(map.getName().c_str(),newIMG.genName(i*3,"ps")) << endl;
		newIMG.WriteFile("FILE/presure.txt");		
		//newIMG.WriteFile
		img.push_back(newIMG);
	}
	return 0;
}