//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=409


#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int checked[25][25] = { 0 };
int map[25][25] = { 0 };
int cnt = 0;
int N;
void DFS(int i, int j)
{
	if (i < 0 || j < 0 || i >= N || j >= N)
		return;
	if (map[i][j] == 1 && checked[i][j] == 0)
	{
		checked[i][j] = 1;
		cnt++;
	}
	else
		return;
	DFS(i + 1, j);
	DFS(i, j + 1);
	DFS(i - 1, j);
	DFS(i, j - 1);

}

int main(void)
{
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
		string str;
		cin >> str;
		
		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	int all_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (checked[i][j] == 0 && map[i][j] == 1)
			{
				all_cnt++;
				DFS(i, j);
				v.push_back(cnt);

				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << all_cnt << endl;
	for (auto x : v)
	{
		cout << x << endl;
	}
	return 0;
}