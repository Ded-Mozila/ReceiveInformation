#include "statistics.h"

void statisticsFun(const VVfloat& pi,const VVfloat& pi_new,const string& nameFile, int i)
{
	vector<float> defferences(TableDifferences(pi,pi_new));
	sort(defferences.begin(),defferences.end());
	ofstream fileStatistics(nameFile.c_str(),std::ofstream::out | std::ofstream::app);
	float M(ExpectedValue(defferences));
	float X_am(AM(defferences));
	fileStatistics << "Interpolation " << i \
	<< "\nArithmetic mean 	:" << X_am \
	<< "\nRoot mean square 	:" << RMS(defferences) \
	<< "\nExpected value 	:" 	<< M \
	<< "\nVariance			:" << Variance(defferences,M) \
	<< "\nStandard Deviation:" << StandardDeviation(defferences,X_am) << '\n';
	fileStatistics.close();
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

float Variance(const vector<float>& arr,const float M)
{
	// D[X] = M[(X-M[X])^2]
	map<float,int> p;
	int count(arr.size());
	//Нахождение вероятностей выпадения чисел
	for (int i = 0; i < count; ++i)
		p[pow((arr[i]-M),2)]++;					
	map<float,int>::iterator k = p.begin();
	float D(0);
	for (k; k != p.end(); ++k)
		D += k->first * k->second;
	return D;
}

float StandardDeviation(const vector<float>& arr,float X_am)
{
	float sigma(0);
	int count(arr.size());
	for (int i = 0; i < count; ++i)
		sigma += pow((arr[i]-X_am),2);
	return pow(sigma/count,0.5);
}