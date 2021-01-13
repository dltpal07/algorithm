//https://programmers.co.kr/learn/courses/30/lessons/42898


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
	int answer = 0;
	vector<vector<bool>> zero(n, vector<bool>(m, true));
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < puddles.size(); i++)
	{
		zero[puddles[i][1] - 1][puddles[i][0] - 1] = false;
	}
	for (int i = 1; i < n; i++)
	{
		if (zero[i][0] == true)
			dp[i][0] = 1;
	}
	for (int j = 1; j < m; j++)
	{
		if (zero[0][j] == true)
			dp[0][j] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (zero[i][0] == false)
		{
			for (int j = i + 1; j < n; j++)
				dp[j][0] = 0;
			break;
		}
	}
	for (int i = 1; i < m; i++)
	{
		if (zero[0][i] == false)
		{
			for (int j = i + 1; j < m; j++)
				dp[0][j] = 0;
			break;
		}
	}
	for (int i = 1; i < dp.size(); i++)
	{
		for (int j = 1; j < dp[i].size(); j++)
		{
			if (zero[i][j] == false)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000007;
			}
		}
	}
	
	answer = dp[n - 1][m - 1];
	return answer;
}

int main(void)
{
	int m = 4, n = 3;
	vector<vector<int>> puddles = { {2, 2} };
	cout << solution(2, 2, {  });
	return 0;
}