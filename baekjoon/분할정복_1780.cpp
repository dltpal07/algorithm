//https://www.acmicpc.net/problem/1780


#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cnt1 = 0, cnt2 = 0, cnt3 = 0;

vector<vector<int>> map;
void solve(int x, int y, int size)
{
	if (size == 1)
	{
		if (map[y][x] == -1)
			cnt1++;
		else if (map[y][x] == 0)
			cnt2++;
		else if (map[y][x] == 1)
			cnt3++;
		return;
	}
	bool same = true;
	short check = map[y][x];
	for (int i = y; i < y + size; i++)
	{
		if (!same)
			break;
		for (int j = x; j < x + size; j++)
		{
			if (check != map[i][j])
			{
				same = false;
				break;
			}
		}
	}

	if (same)
	{
		if (map[y][x] == -1)
			cnt1++;
		else if (map[y][x] == 0)
			cnt2++;
		else if (map[y][x] == 1)
			cnt3++;
		return;
	}
	int newsize = size / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			solve(x + newsize * i, y + newsize * j, newsize);
		}
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> t(n);
		for (int i = 0; i < n; i++)
		{
			cin >> t[i];
		}
		map.push_back(t);

	}
	solve(0, 0, n);
	cout << cnt1<<"\n"<<cnt2<<"\n"<<cnt3;
	return 0;
}