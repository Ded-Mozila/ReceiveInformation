#include "DataImage.h"
#include "settings.h"
#include "stdlib.h"



int test_1(void)
{
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

void test_2(void)
{
	Settings map("settings.txt");
	ListDir test(map.getName(0));	// Start 1 dir
	
	vector<string> fps 	= test.findFile("ps");
	vector<string> fts 	= test.findFile("ts");
	vector<string> fP_1	= test.findFile("P_1");
	test.printDirListVector(fps);
	test.printDirListVector(fts);
	test.printDirListVector(fP_1);
}
int main(int argc, char const *argv[])
{
	//int test = test_1();
	test_2();
	return 0;
}