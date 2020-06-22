//https://www.acmicpc.net/problem/10942


#include <iostream>
#include <algorithm>

using namespace std;
int number[2001];
int dp[2001][2001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> number[i];
	}
	for (int i = 1; i <= N; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 1; i <= N - 1; i++)
	{
		if (number[i] == number[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int k = 3; k <= N; k++)
	{
		for (int i = 1; i <= N - k + 1; i++)
		{
			int j = i + k - 1;
			if (number[i] == number[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = 1;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int st, ed;
		cin >> st >> ed;
		cout << dp[st][ed]<<"\n";
	}
	
	return 0;
}