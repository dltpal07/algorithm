//https://www.acmicpc.net/problem/11651


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
		x.push_back({ b,a});
	}
	sort(x.begin(), x.end());
	for (auto k : x)
	{
		cout << k.second << " " << k.first << "\n";
	}
	return 0;
}
