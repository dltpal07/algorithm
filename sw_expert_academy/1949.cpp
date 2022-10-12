//https://swexpertacademy.com/main/solvingProblem/solvingProblem.do 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> q;

int direct[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int map[9][9] = { 0, };
int bef;
bool visited[9][9] = { false, };
int N, K;
int answer = 0;


void DFS(int cnt, int cur_i, int cur_j)
{
	int nx, ny;
	if (cnt > answer)
	{
		answer = cnt;
	}
	for (int i = 0; i < 4; i++)
	{
		nx = cur_j + direct[i][0];
		ny = cur_i + direct[i][1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx])
		{
			if (map[ny][nx] < map[cur_i][cur_j])
			{
				visited[ny][nx] = true;
				DFS(cnt + 1, ny, nx);
				visited[ny][nx] = false;
			}
		}
	}

}

int main(int argc, char** argv)
{
	int T;
	int test_case;
	int nx, ny, max_val = 0;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, int>> max_v;
		max_val = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		answer = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > max_val)
					max_val = map[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == max_val)
				{
					max_v.push_back({ i, j });
				}
			}
		}
		for (int k = 0; k < max_v.size(); k++)
		{
			int cur_i = max_v[k].first;
			int cur_j = max_v[k].second;
			DFS(1, cur_i, cur_j);
		}
		for (int k = 0; k < max_v.size(); k++)
		{
			int cur_i = max_v[k].first;
			int cur_j = max_v[k].second;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int t = 1; t <= K; t++)
					{
						if (i == cur_i && j == cur_j)
							continue;
						map[i][j] = map[i][j] - t;
						DFS(1, cur_i, cur_j);
						map[i][j] = map[i][j] + t;
					}
				}
			}
		}
		
		cout << "#" << test_case << " " << answer << endl;
	}
		
	return 0;
}
