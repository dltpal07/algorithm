//https://www.acmicpc.net/problem/11051


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int n, k;
int dp[1001][1001] = { 0 };
int main(void)
{

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j || j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	cout << dp[n][k];
	return 0;
}