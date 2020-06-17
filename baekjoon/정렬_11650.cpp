//https://www.acmicpc.net/problem/11650


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int N,a,b;
	vector<pair<int, int>> x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		x.push_back({ a,b });
	}
	sort(x.begin(), x.end());
	for (auto k : x)
	{
		cout << k.first << " " << k.second << "\n";
	}
	return 0;
}
