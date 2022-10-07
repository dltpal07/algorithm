// https://programmers.co.kr/learn/courses/30/lessons/12952

#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
bool chess_board[12][12] = { false, };

bool is_true(int n, int row, int column)
{
	for (int i = 0; i < n; i++)
	{
		if (chess_board[row][i] == true)
			return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (chess_board[i][column] == true)
			return false;
	}
	// left-up diagonal
	for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
	{
		if (chess_board[i][j] == true)
			return false;
	}
	//right-up diagonal
	for (int i = row, j = column; i >= 0 && j < n; i--, j++)
	{
		if (chess_board[i][j] == true)
			return false;
	}
	
	for (int i = row, j = column; i < n && j >= 0; i++, j--)
	{
		if (chess_board[i][j] == true)
			return false;
	}
	for (int i = row, j = column; i < n && j < n; i++, j++)
	{
		if (chess_board[i][j] == true)
			return false;
	}
	return true;
}

void DFS(int cur_i, int cur_j, int cnt, int n)
{
	if (cnt == n)
	{
		answer++;
		return;
	}
	
	for (int j = 0; j < n; j++)
	{
			
		if (is_true(n, cur_i, j))
		{
			chess_board[cur_i][j] = 1;
			cnt++;
			DFS(cur_i+1, j, cnt, n);
			cnt--;
			chess_board[cur_i][j] = 0;
		}
	}
	
}

int solution(int n)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	DFS(0, 0, 0, n);

	return answer;
}

int main(void)
{
	int n = 4;
	cout << solution(n);
	return 0;
}