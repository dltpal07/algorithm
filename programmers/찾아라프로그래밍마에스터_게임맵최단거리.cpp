//https://programmers.co.kr/learn/courses/30/lessons/1844


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dist[101][101];
int bfs(vector<vector<int>> maps)
{
	
	memset(dist, 10001, sizeof(dist));
	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int cur_i = q.front().first;
		int cur_j = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_i + dx[i];
			int ny = cur_j + dy[i];
			if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
				continue;
			if (maps[nx][ny] == 0)
				continue;
			if (dist[nx][ny] > dist[cur_i][cur_j] + 1)
			{
				dist[nx][ny] = dist[cur_i][cur_j] + 1;
				q.push({ nx, ny });
			}
		}
	}
	if (dist[maps.size() - 1][maps[0].size() - 1] >= 10001)
		return -1;
	else
		return dist[maps.size() - 1][maps[0].size() - 1] + 1;
}

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	answer = bfs(maps);
	return answer;
}

int main(void)
{
	vector<vector<int>> maps1 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}},
		maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};
	int answer = solution(maps2);
	cout << answer;
	return 0;
}