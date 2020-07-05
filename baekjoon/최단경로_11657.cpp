//https://www.acmicpc.net/problem/11657

#include <iostream>
#include <vector>

#define MAX 501
#define INF 987654321
using namespace std;

int n, m;
long long bellman[MAX];
vector<pair<pair<int, int>, int>> edge;

void solution()
{
	bellman[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < edge.size(); j++)
		{
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			int cost = edge[j].second;
			if (bellman[from] == INF)
				continue;
			if (bellman[to] > bellman[from] + cost)
			{
				bellman[to] = bellman[from] + cost;
			}
		}
	}
	for (int i = 0; i < edge.size(); i++)
	{
		int from = edge[i].first.first;
		int to = edge[i].first.second;
		int cost = edge[i].second;
		if (bellman[from] == INF)
			continue;
		if (bellman[to] > bellman[from] + cost)
		{
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (bellman[i] == INF)
			cout << -1 << "\n";
		else
			cout << bellman[i] << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		bellman[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ {a,b},c });
	}
	solution();
	return 0;
}