#include "DataImage.h"
#include "settings.h"
#include "stdlib.h"
#include "statistics.h"



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
void test_4_1(int iterm)//рабочий тест
{
	cout <<"Count interpolation = "<< iterm << endl;
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
		string nameMKD(GenNameFile(GenNameFile(GenNameFile(map.getNameDir(),GetStringInt(iterm)),"/"),map.getNameMakeDir(q)));

		mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		vector<string> pslev(dir.findFile("ps_"));
		/// Работа с каждой часовой отметкой
		int ps_size = pslev.size();//Количество чесовых отметок
		for (int h = 0; h < ps_size; ++h)
		{
			vector<string> nlev = dir.findFileHour("P_",lev[h]);
			if(!nlev.empty())
			{
				DataImage newIMG(map.getName(q),h*3);
				cout << "Good Open file: ps_" << h*3 << endl;
				newIMG.MapPmsl();
				VVfloat pi(newIMG.getPresure());// среднее давление на урове моря
				for (int ilev = 0; ilev < iterm; ++ilev)
				{
					GidroFile p(GenNameFile(map.getName(q),nlev[ilev]));
					pi = HInterpolation(pi,p.setVector());
				}
				GidroFile gif(pi);
				string strName(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(h*3)),".txt"));
				map.printInFile(strName,gif);
			}
		}	
	}
	
}
void test_4_2()//Проверка Алгорчитма
{
	Settings map("settings.txt");
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
	// Обход директорий
	for (int q = 0; q < map.getListSize(); ++q)
	{
		cout << map.getName(q) << endl;
		ListDir dir(map.getName(q));
		vector<string> pslev(dir.findFile("ps_"));
		/// Работа с каждой часовой отметкой
		int ps_size = pslev.size();//Количество чесовых отметок
		for (int h = 0; h < ps_size; ++h)
		{
			vector<string> nlev = dir.findFileHour("P_",lev[h]);
			vector<string> hlev = dir.findFileHour("H_",lev[h]);

			if(!nlev.empty())
			{
				DataImage newIMG(map.getName(q),h*3);
				cout << "Good Open file: ps_" << h*3 << endl;
				////////////////////////////////////////////////
				VVfloat geo(newIMG.getHgt());
				// VVfloat geo_new(newIMG.getHgt());
				// for (int ilev = 0; ilev < 30; ++ilev)
				// {
				// 	cout << hlev[ilev];
				// 	string nameMKD(GenNameFile(GenNameFile(GenNameFile(map.getNameDir(),GenNameFile("/",GetStringInt(ilev))),"/"),map.getNameMakeDir(q)));
				// 	mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				// 	GidroFile H(GenNameFile(map.getName(q),hlev[ilev]));
				// 	geo_new = HInterpolation(geo,H.setVector());
				// 	// Статистика
				// 	string nameFileStatistics(GenNameFile(GenNameFile(GenNameFile(map.getNameDir(),"/statistics_geo_"),GetStringInt(h*3)),".txt"));
				// 	statisticsFun(geo,geo_new,nameFileStatistics, ilev+1);
				// 	geo = geo_new;
				// }
				newIMG.addGeopotential(geo);
				///////////////////////////////////////
				newIMG.MapPmsl();
				VVfloat pi(newIMG.getPresure());// среднее давление на урове моря
				//Сохранение Данных по барометрической формуле
				string dirNameP0(MakeString(5,map.getNameDir().c_str(),"/",map.getNameMakeDir(q).c_str(),"P0","/"));//Адрес дериктории с Барометрической формулой
				mkdirp(dirNameP0.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				string strPresure(MakeString(4,dirNameP0.c_str(),"presure_",GetStringInt(h*3).c_str(),".txt"));		// Имя файл P0
				// GidroFile gifPres(pi);																				// Запись в файл P0
				// map.printInFile(strPresure,gifPres);
				VVfloat P0_smth9(pi);
				VVfloat pi_new(newIMG.getPresure());// среднее давление на урове моря
				//создание папки сос татистикой для сгглаженного поля давления 
				//Сглаживания Поле Барометрической формулы
				VVfloat smth9(pi);
				string dirNameP0_smth9_st(MakeString(5,map.getNameDir().c_str(),"/",map.getNameMakeDir(q).c_str(),"P0_smth9_ststic","/"));
				mkdirp(dirNameP0_smth9_st.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				for (int i = 0; i < 16; ++i)
				{
					smth9 = Smth9(pi_new);
					statisticsFun(pi_new,smth9,MakeString(4,dirNameP0_smth9_st.c_str(),"statistics",GetStringInt(h*3).c_str(),".txt"), i+1);
					pi_new = smth9;
					string dirNameP0_smth9(MakeString(5,map.getNameDir().c_str(),"/",map.getNameMakeDir(q).c_str(),"P0_smth9","/"));//Адрес дериктории с Барометрической формулой
					mkdirp(MakeString(2,dirNameP0_smth9.c_str(),GetStringInt(i).c_str()).c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
					string strNameSmth9(MakeString(5,dirNameP0_smth9.c_str(),GetStringInt(i).c_str(),"/presure_",GetStringInt(h*3).c_str(),".txt"));
					GidroFile gifSmth9(smth9);
					map.printInFile(strNameSmth9,gifSmth9);
				}
				// string strNamePs(GenNameFile(GenNameFile(nameMKD,"presure"),".txt"));
				// GidroFile gifPs(pi);
				// map.printInFile(strNamePs,gifPs);
				// int endIter = 23;
				// for (int ilev = 0; ilev < endIter; ++ilev)
				// {
				// 	//string nameMKD(GenNameFile(GenNameFile(GenNameFile(GenNameFile(map.getNameDir(),"    "),GenNameFile("/",GetStringInt(ilev))),"/"),map.getNameMakeDir(q)));
				// 	string nameMKD(MakeString(5,map.getNameDir().c_str(),"/",map.getNameMakeDir(q).c_str(),GetStringInt(ilev).c_str(),"/"));
				// 	cout << nameMKD<< endl;
				// 	mkdirp(nameMKD.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				// 	GidroFile p(GenNameFile(map.getName(q),nlev[ilev]));
				// 	pi_new = HInterpolation(pi,p.setVector());
				// 	// Статистика
				// 	// string nameFileStatistics(GenNameFile(GenNameFile(GenNameFile(map.getNameDir(),"/statistics"),GetStringInt(h*3)),".txt"));
				// 	string nameFileStatistics(MakeString(6,map.getNameDir().c_str(),"/", map.getNameMakeDir(q).c_str(),"statistics",GetStringInt(h*3).c_str(),".txt"));
				// 	cout << nameFileStatistics<< endl;
				// 	statisticsFun(pi,pi_new,nameFileStatistics, ilev+1);
				// 	pi = pi_new;
				// 	// string strName(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(h*3)),".txt"));
				// 	string strName(MakeString(4,nameMKD.c_str(),"presure_",GetStringInt(h*3).c_str(),".txt"));
				// 	GidroFile gif(pi_new);
				// 	map.printInFile(strName,gif);
				// 		// Сгдаживание
				// 	if(ilev+1 == endIter )
				// 	{
				// 		VVfloat smth9(pi);
				// 		for (int i = 0; i < 6; ++i)
				// 		{
				// 			smth9 = Smth9(pi_new);
				// 			statisticsFun(pi,pi_new,nameFileStatistics, ilev+1);
				// 			pi_new = smth9;
				// 			mkdirp(MakeString(3,nameMKD.c_str(),"/smth9/",GetStringInt(i).c_str()).c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				// 			string strNameSmth9(MakeString(6,nameMKD.c_str(),"/smth9/",GetStringInt(i).c_str(),"/presure_",GetStringInt(h*3).c_str(),".txt"));
				// 			GidroFile gifSmth9(smth9);
				// 			map.printInFile(strNameSmth9,gifSmth9);
				// 		}
				// 	}
				// 		// string strNameSmth9(GenNameFile(GenNameFile(GenNameFile(nameMKD,"presure_"),GetStringInt(h*3)),"_smth.txt"));
				// }

			}
		}	
	}
	
}
int main(int argc, char const *argv[])
{
	//int test = test_1();
	//test_2();
	//test_3();
//	test_4_1(atoi(argv[1]));
	test_4_2();/*-------------*/
	return 0;
}