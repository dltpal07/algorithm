//https://programmers.co.kr/learn/courses/30/lessons/12905


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = board[0][0];
	int x = board[0].size();
	int y = board.size();
	for (int i = 1; i < y; i++)
	{
		for (int j = 1; j < x; j++)
		{
			if (board[i][j] == 1)
			{
				board[i][j] = min(board[i][j - 1], board[i - 1][j]);
				board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
				answer = max(answer, board[i][j]);
			}
		}
	}
	return answer * answer;
}

int main(void)
{
	vector<vector<int>> board1 = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}};
	vector<vector<int>> board2 = {{0, 0, 1, 1}, {1, 1, 1, 1}};
	cout << solution(board1);
	return 0;
}