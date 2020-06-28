//https://www.acmicpc.net/problem/1012


#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int checked[50][50];
int cnt = 0;
void DFS(vector<vector<int>> house, int i, int j)
{
	checked[i][j] = 1;
	cnt++;
	if (j - 1 >= 0 && checked[i][j - 1] == 0 && house[i][j - 1] == 1)
	{
		DFS(house, i, j - 1);
	}
	if (j + 1 < house[i].size() && checked[i][j + 1] == 0 && house[i][j + 1] == 1)
	{
		DFS(house, i, j + 1);
	}
	if (i - 1 >= 0 && checked[i-1][j]==0 && house[i-1][j] == 1)
	{
		
		DFS(house, i - 1, j);
	}
	if (i + 1 < house.size()&& checked[i + 1][j] == 0 && house[i + 1][j] == 1)
	{
		DFS(house, i + 1, j);
	}
	
	
	return;
	
}


int main(void)
{
	int t, a, b, c, tmp1, tmp2, all=0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c;
		vector<vector<int>> ground(b, vector<int>(a));
		memset(checked, 0, sizeof(checked));
		all = 0;
		for (int i = 0; i < c; i++)
		{
			cin >> tmp1 >> tmp2;
			ground[tmp2][tmp1] = 1;
		}
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (ground[i][j] == 1 && checked[i][j] == 0)
				{
					all++;
					DFS(ground, i, j);
				}
			}
		}
		
		cout << all<<"\n";
	}
	
	
	return 0;
}