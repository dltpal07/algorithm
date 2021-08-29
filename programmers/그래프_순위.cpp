//https://programmers.co.kr/learn/courses/30/lessons/49191


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	int answer = 0;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
	for (auto r : results)
	{
		graph[r[0]][r[1]] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (graph[j][i] && graph[i][k])
					graph[j][k] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] || graph[j][i])
				cnt++;
		}
		if (cnt == n - 1)
			answer++;
	}
	return answer;
}

int main(void)
{
	int n = 5;
	vector<vector<int>> results = { {4, 3}, {4,2}, {3,2}, {1,2}, {2,5} };
	int result = solution(n, results);
	cout << result;
	return 0;
}