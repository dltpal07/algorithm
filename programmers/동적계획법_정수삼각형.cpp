//https://programmers.co.kr/learn/courses/30/lessons/43105


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = 0;
	vector<vector<int>> dp;
	for (int i = 0; i < triangle.size(); i++)
	{
		vector<int> tmp(triangle[i].size(), 0);
		dp.push_back(tmp);
	}
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}

		}
	}
	int high = triangle.size() - 1, max_val = 0;
	for (int i = 0; i < triangle[high].size(); i++)
	{
		if (dp[high][i] > max_val)
			max_val = dp[high][i];
	}
	return max_val;
}


int main(void)
{
	vector<vector<int>> triangle1 = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
	cout << solution(triangle1);
	return 0;
}