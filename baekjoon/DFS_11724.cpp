//https://www.acmicpc.net/problem/11724


#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;
int checked[MAX];
vector<int> graph[MAX];
int N, M;

void DFS(int node)
{
	checked[node] = 1;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (checked[next] == 0)
		{
			DFS(next);
		}
	}
}

int main(void)
{
	int n1, n2, cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	for (int i = 1; i <= N; i++)
	{
		if (checked[i] == 0)
		{
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}