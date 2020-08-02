//https://www.acmicpc.net/problem/1267


#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

	int N, sum1 = 0, sum2 = 0;
	cin >> N;
	vector<double> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < N; i++)
	{
		double div;
		div = ceil((v[i] +1)/ 30);
		sum1 += div * 10;
		div = ceil((v[i] +1)/ 60);
		sum2 += div * 15;
	}
	if (sum1 < sum2)
	{
		cout << "Y " << sum1;
	}
	else if(sum1 == sum2)
	{
		cout << "Y M " << sum1;
	}
	else
	{
		cout << "M " << sum2;
	}
	return 0;
}