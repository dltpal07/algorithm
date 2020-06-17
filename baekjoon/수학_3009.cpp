//https://www.acmicpc.net/problem/3009


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int a, b,result_a,result_b;
	vector<int> x;
	vector<int> y;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	for (auto k : x)
	{
		if (count(x.begin(), x.end(), k) == 1)
		{
			result_a = k;
			break;
		}
	}
	for (auto k : y)
	{
		if (count(y.begin(), y.end(), k) == 1)
		{
			result_b = k;
			break;
		}
	}
	cout << result_a << ' ' << result_b ;
	return 0;
}