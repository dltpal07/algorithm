//https://www.acmicpc.net/problem/2565


#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int MAX = 501;
pair<int, int> connect[MAX];
int cache[MAX];

int LIS()
{
	int idx = 0;
	int length = 0;
	cache[idx] = connect[0].second;
	for (int i = 1; i < N; i++)
	{
		if (cache[idx] < connect[i].second)
		{
			cache[++idx] = connect[i].second;
		}
		else
		{
			int idx2 = lower_bound(cache, cache + idx, connect[i].second) - cache;
			cache[idx2] = connect[i].second;
			length++;
		}
	}
	return length;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> connect[i].first >> connect[i].second;
	}
	sort(connect, connect + N);
	cout << LIS() << "\n";
	
	return 0;
}