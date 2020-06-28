//https://www.acmicpc.net/problem/2206


#include <iostream>
#include <string>
#include <queue>

#define MAX 1000
using namespace std;

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX][2];

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0}, {0,1} });
	visit[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int br = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			return cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (map[nx][ny] == 1 && br == 0)
				{
					visit[nx][ny][br + 1] = true;
					q.push({ { nx, ny }, { br + 1, cnt + 1 } });
				}
				else if (map[nx][ny] == 0 && visit[nx][ny][br] == false)
				{
					visit[nx][ny][br] = true;
					q.push({ {nx, ny}, {br, cnt + 1} });
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = tmp[j] - '0';
		}
	}
	cout << BFS();
	return 0;
}