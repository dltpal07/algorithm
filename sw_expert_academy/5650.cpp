//https://swexpertacademy.com/main/solvingProblem/solvingProblem.do


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int N;
int board[101][101] = { 0, };
int direct[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int max_val = 0;
int sum_val = 0;

struct warmhole {
	int i, j;
};



int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(board, 0, sizeof(board));
		map<int, vector<warmhole>> m;
		max_val = 0;
		sum_val = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
				if (board[i][j] >= 6 && board[i][j] <= 10)
				{
					m[board[i][j]].push_back({ i, j });
				}
			}
		}
	
		for (int cur_i = 0; cur_i < N; cur_i++)
		{
			for (int cur_j = 0; cur_j < N; cur_j++)
			{
				if (board[cur_i][cur_j] != 0)
					continue;
				
				int ni, nj;
				int cur_x, cur_y;
				for (int d = 0; d < 4; d++)
				{
					cur_x = direct[d][0];
					cur_y = direct[d][1];
					ni = cur_i + cur_y;
					nj = cur_j + cur_x;
					sum_val = 0;
					while (1)
					{
						if (sum_val > max_val)
							max_val = sum_val;
						if (ni < 0 || ni >= N || nj < 0 || nj >= N) // 벽
						{
							sum_val++;
							cur_x *= -1;
							cur_y *= -1;
							ni += cur_y;
							nj += cur_x;
						}
						else if (ni == cur_i && nj == cur_j) // 종료
							break;
						else if (board[ni][nj] == -1) // 블랙홀
							break;
						else if (board[ni][nj] >= 6 && board[ni][nj] <= 10) // 웜홀
						{
							if (ni == m[board[ni][nj]][0].i && nj == m[board[ni][nj]][0].j)
							{
								int new_ni = m[board[ni][nj]][1].i;
								int new_nj = m[board[ni][nj]][1].j;

								ni = new_ni + cur_y;
								nj = new_nj + cur_x;
							}
							else
							{
								int new_ni = m[board[ni][nj]][0].i;
								int new_nj = m[board[ni][nj]][0].j;

								ni = new_ni + cur_y;
								nj = new_nj + cur_x;
							}
						}
						else if (board[ni][nj] >= 1 && board[ni][nj] <= 5) // 블록
						{
							sum_val++;
							if (board[ni][nj] == 1)
							{
								if ((cur_x == 1 && cur_y == 0) || (cur_x == 0 && cur_y == -1))
								{
									cur_x *= -1;
									cur_y *= -1;
								}
								else
								{
									int tmp;
									tmp = cur_x;
									cur_x = cur_y;
									cur_y = tmp;
								}
							}
							else if (board[ni][nj] == 2)
							{
								if ((cur_x == 1 && cur_y == 0) || (cur_x == 0 && cur_y == 1))
								{
									cur_x *= -1;
									cur_y *= -1;
								}
								else
								{
									cur_x *= -1;
									cur_y *= -1;
									int tmp;
									tmp = cur_x;
									cur_x = cur_y;
									cur_y = tmp;
								}
							}
							else if (board[ni][nj] == 3)
							{
								if ((cur_x == 0 && cur_y == 1) || (cur_x == -1 && cur_y == 0))
								{
									cur_x *= -1;
									cur_y *= -1;
								}
								else
								{
									int tmp;
									tmp = cur_x;
									cur_x = cur_y;
									cur_y = tmp;
								}
							}
							else if (board[ni][nj] == 4)
							{
								if ((cur_x == -1 && cur_y == 0) || (cur_x == 0 && cur_y == -1))
								{
									cur_x *= -1;
									cur_y *= -1;
								}
								else
								{
									cur_x *= -1;
									cur_y *= -1;
									int tmp;
									tmp = cur_x;
									cur_x = cur_y;
									cur_y = tmp;
								}
							}
							else if (board[ni][nj] == 5)
							{
								cur_x *= -1;
								cur_y *= -1;
								
							}
							ni += cur_y;
							nj += cur_x;
						}
						else if (board[ni][nj] == 0) // 방향 유지
						{
							ni += cur_y;
							nj += cur_x;
						}

					}
				}
			}
		}
		cout << "#" << test_case << " " << max_val << endl;
	}

		
	return 0;
}
