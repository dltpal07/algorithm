//https://www.acmicpc.net/problem/2178


#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int direct[4][2] = { {0, -1}, {1,0}, {0,1},{-1,0} };
int maze[101][101];
queue <pair<int, int>> q;

void bfs()
{
	q.push({ 0,0 });
	pair<int, int> cur;
	int nx, ny;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = cur.second + direct[i][0];
			ny = cur.first + direct[i][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1)
			{
				q.push({ ny, nx });
				maze[ny][nx] = maze[cur.first][cur.second] + 1;
			}
		}
	}
	return;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = str[j] - '0';
		}
		
	}
	bfs();
	cout << maze[N - 1][M - 1];
	return 0;
}