//https://programmers.co.kr/learn/courses/30/lessons/1829


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max_size;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1,0,0 };

bool visit[100][100];

int BFS(int a, int b, int m, int n, vector<vector<int>> MAP)
{
	int color = MAP[a][b];
	int size = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (q.empty() == 0)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m&&ny < n)
			{
				if (MAP[nx][ny] == color && visit[nx][ny] == false)
				{
					visit[nx][ny] = true;
					q.push({ nx, ny });
					size++;
				}
			}
		}
	}
	return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = false;
		}
	}
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] != 0 && visit[i][j] == false)
			{
				int size = BFS(i, j, m, n, picture);
				if (size > max_size_of_one_area)
					max_size_of_one_area = size;
				number_of_area++;
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main(void)
{
	int m = 6, n = 4;
	vector<vector<int>> picture = { {1, 1, 1, 0}, {1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };
	vector<int> answer = solution(m, n, picture);
	cout << answer[0] << " " << answer[1];
	return 0;
}