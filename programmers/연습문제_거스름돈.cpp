//https://programmers.co.kr/learn/courses/30/lessons/12907


#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long dp[100001];

int solution(int n, vector<int> money)
{
	int answer = 0;
	dp[0] = 1;
	for (int i = money[0]; i <= n; i += money[0])
	{
		dp[i] = 1;
	}
	for (int i = 1; i < money.size(); i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j >= money[i])
				dp[j] += dp[j - money[i]] % 1000000007;
		}
	}
	answer = dp[n];
	return answer;
}

int main(void)
{
	int n = 5;
	vector<int> money = { 1, 2, 5 };
	int answer = solution(n, money);
	cout << answer;
	return 0;
}