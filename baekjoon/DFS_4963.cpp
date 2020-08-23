//https://www.acmicpc.net/problem/4963


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dir_i[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
int dir_j[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
bool checked[51][51];
int land[51][51];

void DFS(int cur_i, int cur_j)
{
	checked[cur_i][cur_j] = true;
	for (int i = 0; i < 8; i++)
	{
		int next_i = cur_i + dir_i[i];
		int next_j = cur_j + dir_j[i];
		if (land[next_i][next_j] == 1 && checked[next_i][next_j] == false)
		{
			DFS(next_i, next_j);
		}
	}
}

int main(void)
{
	

	while (true)
	{
		int w, h, cnt = 0;
		memset(checked, false, sizeof(checked));
		memset(land, 0, sizeof(land));
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> land[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (checked[i][j] == false && land[i][j] == 1)
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}
