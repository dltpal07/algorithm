//https://www.acmicpc.net/problem/7576


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

# define MAX 1001
int m, n;

using namespace std;

int tomato[MAX][MAX]; // 토마토 상태
queue<pair<int, int>> startPoint;
int dy[4] = { 1,0,-1,0 }; // 위, 오른쪽, 아래, 왼쪽
int dx[4] = { 0,1,0,-1 };

int bfsValue, nextValue;

void bfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0) // 범위 확인
			continue;
		if (tomato[nextY][nextX] == 0)
		{
			tomato[nextY][nextX] = 1;
			nextValue++;
			startPoint.push({ nextY, nextX }); // 다음 확인할 큐
		}
	}
	return;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				startPoint.push({ i,j });
		}
	}

	bfsValue = startPoint.size();
	nextValue = 0;
	int ret = 0;
	while (startPoint.size())
	{
		pair<int, int> start = startPoint.front();
		bfs(start.first, start.second);
		bfsValue--;
		if (bfsValue == 0)
		{
			bfsValue = nextValue;
			nextValue = 0;
			ret++;
		}
		startPoint.pop();
	}
	ret -= 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tomato[i][j] == 0)
				ret = -1;
		}
	}
	cout << ret << "\n";
	return 0;
}
