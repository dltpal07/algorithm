//https://www.acmicpc.net/problem/2606


#include <iostream>
#include <vector>
using namespace std;
int N, M, cnt=0;
int adjacent[101][101];
bool visited[101];

void DFS(int idx)
{
	cnt++;
	for (int i = 1; i <= N; i++)
	{
		if (adjacent[idx][i] && (!visited[i]))
		{
			visited[i] = 1;
			DFS(i);
		}
	}
}


int main(void)
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adjacent[a][b] = 1;
		adjacent[b][a] = 1;
	}
	visited[1] = 1;
	DFS(1);
	cout << cnt - 1;
	
	return 0;
}