//https://www.acmicpc.net/problem/2667


#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int checked[25][25];
int cnt = 0;
void DFS(vector<vector<int>> house, int i, int j)
{
	checked[i][j] = 1;
	cnt++;
	if (i - 1 >= 0 && checked[i-1][j]==0 && house[i-1][j] == 1)
	{
		
		DFS(house, i - 1, j);
	}
	if (i + 1 < house.size()&& checked[i + 1][j] == 0 && house[i + 1][j] == 1)
	{
		DFS(house, i + 1, j);
	}
	if (j - 1 >= 0 && checked[i ][j-1] == 0 && house[i ][j- 1] == 1)
	{
		DFS(house,  i, j - 1);
	}
	if (j + 1 < house.size() && checked[i ][j+ 1] == 0 && house[i][j + 1] == 1)
	{
		DFS(house,  i, j + 1);
	}
	
	return;
	
}


int main(void)
{
	int N, all=0;
	vector<vector<int>> house;
	vector<int> result;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		vector<int> tmp;
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			tmp.push_back(str[j]-'0');
		}
		house.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (house[i][j] == 1 && checked[i][j] == 0)
			{
				all++;
				DFS(house, i, j);
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}
	

	cout << all << endl;
	sort(result.begin(), result.end());
	for (auto x : result)
	{
		cout << x << "\n";
	}
	return 0;
}