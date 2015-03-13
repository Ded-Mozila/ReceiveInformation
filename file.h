#include "header.h"
#ifndef FILE_H
#define FILE_H
// Базовый класс для работы с фалами
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

// Класс для работы с конкретным файлом для его обработки и хранения информации из него

class GidroFile
{
private:
	string name;		// Имя файла	
	int column;			// Количество столбцов в матрицы	
	int row; 			// Количество строк в матрицы
	float maxElement;	// Максимальное занечение в матрицы
	float minElement;	// Минимальное значени е в файле
	VVfloat matrixMap;	// Матрица(сетка) значений относительно карты
public:
	GidroFile(){};			// Конструктор по умолчанию
	GidroFile(string);		// Конструктор который принимает строку имени файла	
	void OpenFile(string);	// Открыйтие и считываение файловых данных	
	VVfloat setVector(void);	// Возвращает значение 
	string setName(void);		// Возвращает имя файла
	int setColumn(void);		// Возвращает длину столбца матрицы
	int setRow(void);			// Возвращает длину строки матрицы
	float setMaxElement(void);	// Возвращает максимальный элемент из матрицы
	float setMinElement(void);	// Возвращает минимальный элемент из матрицы
	GidroFile & operator= (const GidroFile&); //Оператор присваивания

	~GidroFile(){};			// Деструктор по умолчанию
};

// Класс для работы со списоком файлов, которые расположеный в директории

class ListDir
{
private:
	string name;					// Cтрока директории
	vector<string> listNameFile;	// Список файлов директории
	int getdir(void);				// Поиск в дериктории файлов
public:
	ListDir(){};					// Конструктор по-умолчнию
	ListDir(string);				// Конструктор который принимаетстроку дериктории с которой нужно работать
	~ListDir(){};
	//void printElementList(string nameFile); непонятно почему не работает!
	void printDirList(void);		// Вывод на экран списка файлов из директории
};	


#endif