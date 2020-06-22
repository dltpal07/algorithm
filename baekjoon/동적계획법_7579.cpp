//https://www.acmicpc.net/problem/7579


#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int memory[101];
int cost[101];
int dp[10001][100];
int list[10001];


int process()
{
	int c, mem;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 10000; j++) 
		{
			if (dp[j][i - 1] >= 0)
			{
				if (dp[j][i - 1] > dp[j][i])
					dp[j][i] = dp[j][i - 1];
				if (dp[j][i - 1] + memory[i] > dp[j + cost[i]][i])
					dp[j + cost[i]][i] = dp[j][i - 1] + memory[i];
			}
		}
	}
	int j = 0;
	while (j <= 10000 && dp[j][n] < m)
		j++;
	return j;
}

int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> memory[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	cout << process();
	return 0;
}