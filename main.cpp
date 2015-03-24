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
	Settings map("settings.txt");
	vector<vector<DataImage> > listGif;
	int mapSize = map.getListSize();
	for (int j = 0; j < mapSize; ++j)// по директориям
	{
		string nameMKD(map.getNameMakeDir(j));								//	Созжание стороки дериктории для записи данных
		mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);		//	Создание директории для картинок и файлов
		vector<DataImage> img;
		// GidroFile hgt((GenNameFile(map.getName(j),"hgt.grd"))); 			// Открытие файла с высотами  местности												//	Все картинки за 72 часа
		map.printLatLon(map.getName(j),nameMKD);							// Запись в каждую дерикторию lat и lon										
		for (int i = 0; i < map.getN()+1; i=i+3)
		{
			cout << "Open file: ps_" << i << endl;
			DataImage newIMG(map.getName(j),i);
			// newIMG.addHgt(hgt);
			cout << "Good Open file: ps_" << i << endl;
			newIMG.MapPmsl();
			//newIMG.HorizontalInterpolation_gif();
			cout << "Good MapPmsl file: ps_" << i << endl;
			string str(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(i)),".txt"));
			newIMG.WriteFile(str);		
			//img.push_back(newIMG);
			cout << "Good make file: presure_" << i<< endl;
		}
		//listGif.push_back(img);
	}
	return 0;
}