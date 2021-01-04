//https://programmers.co.kr/learn/courses/30/lessons/12913


#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
	int answer = 0;
	vector<vector<int>> dp(land.size(), vector<int>(land[0].size()));
	for (int i = 0; i < land.size(); i++)
	{
		
		for (int j = 0; j < land[i].size(); j++)
		{
			if (i == 0)
				dp[i][j] = land[i][j];
			else
			{
				int max_val = 0;
				for (int k = 0; k < land[i].size(); k++)
				{
					if (j != k)
					{
						if (max_val < dp[i - 1][k])
						{
							max_val = dp[i - 1][k];
						}
					}
				}
				dp[i][j] = land[i][j] + max_val;
			}
		}
	}
	for (int i = 0; i < dp[0].size(); i++)
	{
		if (answer < dp[land.size() - 1][i])
		{
			answer = dp[land.size() - 1][i];
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> land = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
	cout << solution(land);
	return 0;
}