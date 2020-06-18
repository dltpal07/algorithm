//https://www.acmicpc.net/problem/10844


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define mod 1000000000;
int DP[101][10];
int main(void)
{
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				DP[i][j] = DP[i - 1][j + 1];
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j - 1];
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % mod;
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		sum += DP[n][i];
	}
	cout << sum % mod;
	
	return 0;
}