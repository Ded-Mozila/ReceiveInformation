#ifndef STATISTICS_H
#define STATISTICS_H
#include "header.h"

void statisticsFun(const VVfloat&,const VVfloat&);			//Основа для всех функций 
VVfloat TableDifferences(const VVfloat&,const VVfloat&); 	//Таблица разницы между двкмя итерациями
float RMS(const VVfloat&);									//Root mean square или Средее квадратичное 
float AM(const VVfloat&);									//Arithmetic mean или Средее арифметическое
float Variance(const VVfloat&,const float& M);				//Дисперсия
float StandardDeviation(const VVfloat&,float X_am);			//Среднеквадратическое отклонение
#endif
