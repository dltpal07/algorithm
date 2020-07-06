//https://www.acmicpc.net/problem/11404


#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 101
int from, to, weight;
int m, n;
int node[MAX][MAX];

void floyd_warshall()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (node[j][i] != INF && node[i][k] != INF)
				{
					node[j][k] = min(node[j][k], node[j][i] + node[i][k]);
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			node[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> weight;
		if (node[from][to] > weight)
		{
			node[from][to] = weight;
		}
	}
	floyd_warshall();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || node[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << node[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}