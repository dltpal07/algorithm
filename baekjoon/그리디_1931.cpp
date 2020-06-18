//https://www.acmicpc.net/problem/1931


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
	int n,cnt=0,_max=0,pt=0, st = 0;
	cin >> n;
	vector<pair<int, int>> m(n);
	for (int i = 0; i < n; i++)
	{
		cin >> m[i].second >> m[i].first;
	}
	sort(m.begin(), m.end());
	for (int i = 0; i < n; i++)
	{
		if (st <= m[i].second)
		{
			st = m[i].first;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}