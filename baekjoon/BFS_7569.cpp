//https://www.acmicpc.net/problem/7569


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;
int dy[6] = { 1,0,-1,0,0,0 }; // 앞, 오른쪽, 뒤, 왼쪽, 위, 아래 
int dx[6] = { 0,1,0,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int tomato[100][100][100];

queue<vector<int>> startPoint;
int bfsValue, nextValue;

void bfs(int h, int y, int x)
{
	for (int i = 0; i < 6; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		int nextH = h + dh[i];
		if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0 || nextH >= H || nextH < 0)
			continue;
		if (tomato[nextH][nextY][nextX] == 0)
		{
			tomato[nextH][nextY][nextX] = 1;
			nextValue++;
			startPoint.push({ nextH, nextY, nextX });
		}
	}
	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					startPoint.push({ i,j,k });
				}
			}
		}
	}
	bfsValue = startPoint.size();
	nextValue = 0;
	int ret = 0;
	while (startPoint.size())
	{
		vector<int> start = startPoint.front();
		bfs(start[0], start[1], start[2]);
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
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 0)
					ret = -1;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}