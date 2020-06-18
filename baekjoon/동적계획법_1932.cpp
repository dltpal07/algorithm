//https://www.acmicpc.net/problem/1932


#include <iostream>
#include <vector>
#include <string>
using namespace std;
int DP[501][501];
int MAX(int a, int b)
{
	return a > b ? a : b;
}


int main(void)
{
	int n, _max = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> DP[i][j];
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == 1)
			{
				DP[i][j] += DP[i - 1][j];
			}
			else if (j == n)
			{
				DP[i][j] += DP[i - 1][j - 1];
			}
			else
			{
				DP[i][j] += MAX(DP[i - 1][j], DP[i - 1][j - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		_max = MAX(_max, DP[n][i]);
	}
	cout << _max;
	return 0;
}