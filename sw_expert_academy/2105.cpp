// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int board[21][21] = { 0, };
int visited[21][21] = { 0, };
int dessert[101] = { 0, };
int N;
int direct[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
queue<pair<int, int>> q;
int st_i, st_j;
int max_val = 0;
void DFS(int cur_i, int cur_j, int cur_direct, int sum_val)
{
	if (sum_val > 0 && cur_i == st_i && cur_j == st_j)
	{
		if (max_val < sum_val)
		{
			max_val = sum_val;
			
		}
		return;
	}
	int nx, ny;
	for (int i = cur_direct; i < 4; i++)
	{
		
		nx = cur_j + direct[i][0];
		ny = cur_i + direct[i][1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && dessert[board[ny][nx]] == 0)
		{

			dessert[board[ny][nx]] = 1;
			DFS(ny, nx, i , sum_val + 1);
			dessert[board[ny][nx]] = 0;

			
		}

	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(board, 0, sizeof(board));
		max_val = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				st_i = i;
				st_j = j;
				memset(visited, 0, sizeof(visited));
				memset(dessert, 0, sizeof(dessert));
				DFS(i, j, 0, 0);
			}
		}
		if (max_val < 3)
			cout << "#" << test_case << " " << -1 << "\n";
		else
			cout << "#" << test_case << " " << max_val << "\n";
	}
	return 0;
}