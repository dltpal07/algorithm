//https://www.acmicpc.net/problem/1138


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void)
{
	int n, a, cnt;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < i; j++)
		{
			if (v[i].second < v[j].second)
			{
				cnt++;
			}
			if (cnt == v[i].first+1)
			{
				
				v.insert(v.begin() + j, v[i]);
				v.erase(v.begin() + i + 1);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << v[i].second << " " ;
	}
	return 0;
}