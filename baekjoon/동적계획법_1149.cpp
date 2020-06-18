//https://www.acmicpc.net/problem/1149


#include <iostream>
using namespace std;
#define endl "\n"
#define MAX 1000 + 1

int N, Answer;
int map[MAX][3];
int dp[MAX][3];
int Min(int A, int B)
{
	if (A < B)
		return A;
	return B;
}

int main(void)
{
	int n;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	map[0][0] = map[0][1] = map[0][2] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = Min(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
		dp[i][1] = Min(dp[i - 1][0], dp[i - 1][2]) + map[i][1];
		dp[i][2] = Min(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
	}	
	Answer = Min(Min(dp[N][0], dp[N][1]), dp[N][2]);
	cout << Answer;
	return 0;
}