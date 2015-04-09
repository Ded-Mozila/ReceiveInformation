#ifndef STATISTICS_H
#define STATISTICS_H
#include "header.h"

void statisticsFun(const VVfloat&,const VVfloat&,const string&);					//Основа для всех функций 
vector<float> TableDifferences(const VVfloat&,const VVfloat&); 		//Таблица разницы между двкмя итерациями
float RMS(const vector<float>&);									//Root mean square или Средее квадратичное 
float AM(const vector<float>&);										//Arithmetic mean или Средее арифметическое
float ExpectedValue(const vector<float>&);							//Математическое ожидание
float Variance(const vector<float>&,const float M);					//Дисперсия
float StandardDeviation(const vector<float>&,float X_am);			//Среднеквадратическое отклонение
#endif
