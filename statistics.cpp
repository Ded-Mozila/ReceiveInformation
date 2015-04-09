#include "statistics.h"

void statisticsFun(const VVfloat& pi,const VVfloat& pi_new,const string& nameFile)
{
	vector<float> defferences(TableDifferences(pi,pi_new));
	sort(defferences.begin(),defferences.end());
	float rms = RMS(defferences);
}

vector<float> TableDifferences(const VVfloat& pi ,const VVfloat& pi_new)
{
	vector<float> deff(400 * 500);
	int count = pi.size();
	int n = pi[0].size();
	int q = 0;
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < n; ++j)
			deff[++q] = fabs(pi[i][j]-pi_new[i][j]);
	return deff;
}
float RMS(const vector<float>& arr)
{
	float rms(0);
	int count(arr.size());
	for (int i = 0; i < count; ++i)
		rms += arr[i]*arr[i];
	return pow((rms/count), 0.5);
}

float AM(const vector<float>& arr)
{
	float am(0);
	int count(arr.size());
	for (int i = 0; i < count; ++i)
		am += arr[i];
	return am/count;
}

float ExpectedValue(const vector<float>& arr)
{
	map<float,int> p;
	int count(arr.size());
	//Нахождение вероятностей выпадения чисел
	for (int i = 0; i < count; ++i)
		p[arr[i]]++;
	map<float,int>::iterator k = p.begin();
	float M(0);
	for (k; k != p.end(); ++k)
		M += k->first * k->second;
	return M;
}