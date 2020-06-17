//https://www.acmicpc.net/problem/1018


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 50;
int M, N;
string board[MAX];
string whiteFirst[8] = {
{ "WBWBWBWB" },
{ "BWBWBWBW" },
{ "WBWBWBWB" },
{ "BWBWBWBW" },
{ "WBWBWBWB" },
{ "BWBWBWBW" },
{ "WBWBWBWB" },
{ "BWBWBWBW" }
};
string blackFirst[8] = {
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};
int whiteFirstChange(int x, int y)
{
	int cnt = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (board[i][j] != blackFirst[i-x][j-y])
				cnt++;
		}
	}
	return cnt;
}

int blackFirstChange(int x, int y)
{
	int cnt = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (board[i][j] != whiteFirst[i-x][j-y])
				cnt++;
		}
	}
	return cnt;
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	int result = INF;
	for (int i = 0; i < N - 8 + 1; i++)
	{
		for (int j = 0; j < M - 8 + 1; j++)
		{
			result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));
		}
	}
	cout << result;

	return 0;
}