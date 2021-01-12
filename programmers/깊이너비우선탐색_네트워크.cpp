//https://programmers.co.kr/learn/courses/30/lessons/43162


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checked[200] = { 0 };

void DFS(int cur, int n, vector<vector<int>> com)
{
	checked[cur] = 1;
	for (int j = 0; j < n; j++)
	{
		if (com[cur][j] == 1 && checked[j] == 0)
			DFS(j, n, com);
	}
	
	
}


int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (checked[i] == 0)
		{
			answer++;
			DFS(i, n, computers);
		}
	}
	return answer;
}

int main(void)
{
	int n1 = 3, n2 = 3;
	vector<vector<int>> computers1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	vector<vector<int>> computers2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	cout << solution(n1, computers1);
	return 0;
}