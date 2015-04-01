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

// void test_2(void)
// {
// 	Settings map("settings.txt");
// 	int  i = 0;
// 	ListDir test(map.getName(i));	// Start 1 dir
	
// 	vector<string> fps 	= test.findFile("ps");
// 	vector<string> fts 	= test.findFile("ts");
// 	vector<string> fP_1	= test.findFile("P_1");
// 	test.printDirListVector(fps);
// 	test.printDirListVector(fts);
// 	test.printDirListVector(fP_1);
// 	string nameMKD(map.getNameMakeDir(i));
// 	mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
// 	map.printLatLon(map.getName(i),nameMKD);
// 	for (int j = 0; j < fts.size(); ++j)
// 	{
// 		DataImage fl_ps(GenNameFile(map.getName(i),fps[j]),GenNameFile(map.getName(i),fts[j]),GenNameFile(map.getName(i),"hgt.grd"));
// 		fl_ps.MapPmsl();
// 		GidroFile P_1(GenNameFile(map.getName(i),fP_1[j]));
// 		fl_ps.HorizontalInterpolation_gif(P_1.setVector());
// 		cout << "Good MapPmsl file: ps_" << i << endl;
// 		string str(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(i)),".txt"));
// 		fl_ps.WriteFile(str);	
// 	}
// }

void test_3()
{
	//Тестирую случай один из тетради
	Settings map("settings.txt");
	int  q = 0;
	ListDir test(map.getName(q));	// Start 1 dir /2013.12.11/

	vector<string> fP_100   = test.findFile("P_1.000_072"); //1000  i+1
	vector<string> fP_968	= test.findFile("P_0.968_072"); //968  	i
	vector<string> fP_930	= test.findFile("P_0.930_072"); //930  	i-1
	string nameMKD(map.getNameMakeDir(q));
	mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	for (int k = 0; k < fP_100.size(); ++k)
	{
		// Открытие файлов
		GidroFile P_100(GenNameFile(map.getName(q),fP_100[k]));
		GidroFile P_968(GenNameFile(map.getName(q),fP_968[k]));
		GidroFile P_930(GenNameFile(map.getName(q),fP_930[k]));
		GidroFile Ps(GenNameFile(map.getName(q),"ps_072.grd"));

		vector<float> one_string(500,1000);
		// VVfloat table_Ps(400,one_string);
		VVfloat table_Ps(Ps.setVector());
		GidroFile gif(table_Ps);
		map.printInFile(GenNameFile(nameMKD,"test2.txt"),gif);
		VVfloat pi;
		for (int i = 0; i < table_Ps.size(); ++i)
		{	
			one_string.clear();
			for (int j = 0; j < table_Ps[i].size(); ++j)
			{
				float a = table_Ps[i][j]+P_100.At(i,j)-2*P_968.At(i,j)+P_930.At(i,j);
				//cout << a << endl;
				one_string.push_back(a);
			}
			pi.push_back(one_string);
		}
		// GidroFile gif(pi);
		// map.printInFile(GenNameFile(nameMKD,"test2.txt"),gif);
	}

}
//Удачиный тест программы
void test_4()
{
	Settings map("settings.txt");
	int  q = 0;
	ListDir test(map.getName(q));	// Start 1 dir /2013.12.11/
	string nameMKD(map.getNameMakeDir(q));
	mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	vector<string> nlev;	// Список уровней
	//получение списка уравней
		string str;
		ifstream file_nlev("nlev.txt");
		while(file_nlev >> str)
			nlev.push_back(str);
		int count = nlev.size();
		file_nlev.close();
	// Получение налального приближенного даления на уровне моря
		cout << "Open file: ps_" << 72 << endl;
		DataImage newIMG(map.getName(q),72);
		cout << "Good Open file: ps_" << 72 << endl;
		newIMG.MapPmsl();
	////////////////////////////////////////////////////////////
	VVfloat pi(newIMG.getPresure());// среднее давление на урове моря
	// N операций отколичества итераций
	for (int ilev = 0; ilev < count; ++ilev)
	{
		GidroFile p(GenNameFile(map.getName(q),nlev[ilev]));
		pi = HInterpolation(pi,p.setVector());
		//cout << nlev[ilev] << endl;
	}
	GidroFile gif(pi);
	map.printInFile(GenNameFile(nameMKD,"test2.txt"),gif);	
}
void test_4_1()
{
	Settings map("settings.txt");
	// Обход директорий
	vector<string> lev;	// Список уровней
		string str;
		ifstream file_nlev("nlev.txt");
		while(file_nlev >> str)
		{
			lev.push_back(str);
			cout << str << endl;	
		}
		int count = lev.size();
		file_nlev.close();
	//////////////////////////////////////////
	for (int q = 0; q < map.getListSize(); ++q)
	{
		cout << map.getName(q) << endl;
		ListDir dir(map.getName(q));
		string nameMKD(map.getNameMakeDir(q));
		mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		int k = 0;
		/// Работа с каждой часовой отметкой
		for (int h = 0; h < 73; h=h+3)
		{
			vector<string> nlev = dir.findFileHour("P_",lev[k]);
			k++;
			if(!nlev.empty())
			{
				DataImage newIMG(map.getName(q),h);
				cout << "Good Open file: ps_" << h << endl;
				newIMG.MapPmsl();
				VVfloat pi(newIMG.getPresure());// среднее давление на урове моря
				for (int ilev = 0; ilev < count; ++ilev)
				{
					GidroFile p(GenNameFile(map.getName(q),nlev[ilev]));
					pi = HInterpolation(pi,p.setVector());
				}
				GidroFile gif(pi);
				string strName(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(h)),".txt"));
				map.printInFile(strName,gif);
			}
		}	
	}
	
}
int main(int argc, char const *argv[])
{
	//int test = test_1();
	//test_2();
	//test_3();
	test_4_1();
	return 0;
}