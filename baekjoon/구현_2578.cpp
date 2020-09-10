//https://www.acmicpc.net/problem/2578


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int board[5][5];
	int quest[25];
	int r_c[5] = {0};
	int c_c[5] = {0};
	int l = 0, r = 0;
	vector<pair<int, int>> v(25);
	
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tmp;
			cin >> tmp;
			board[i][j] = tmp;
			v[tmp - 1] = { i,j };
		}
	}
	for (int i = 0; i < 25; i++)
	{
		cin >> quest[i];
	}
	for (int i = 0; i < 25; i++)
	{
		int tmp;
		tmp = quest[i];
		r_c[v[tmp - 1].first]++;
		c_c[v[tmp - 1].second]++;
		if (v[tmp - 1].first == v[tmp - 1].second)
			l++;
		if (v[tmp - 1].first == 4 - v[tmp - 1].second)
			r++;

		if (r_c[v[tmp - 1].first] == 5)
			cnt++;
		if (c_c[v[tmp - 1].second] == 5)
			cnt++;
		if (l == 5)
		{
			cnt++;
			l = 0;
		}
		if (r == 5)
		{
			cnt++;
			r = 0;
		}
		if (cnt >= 3)
		{
			cout << i + 1;
			break;
		}
	}
	return 0;
}