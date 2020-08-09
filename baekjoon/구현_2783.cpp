//https://www.acmicpc.net/problem/2783


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<pair<double, double>> v;
	int cnt;
	double a, b, min = 987654321, comp;
	cin >> a >> b;
	v.push_back({ a, b });
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++)
	{
		comp = v[i].first / v[i].second * 1000;
		if (min > comp)
			min = comp;
	}
	cout << min;
	return 0;
}