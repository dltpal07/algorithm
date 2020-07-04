//https://www.acmicpc.net/problem/1753


#include <iostream>
#include <queue>
#include <vector>

#define MAX 20001
#define INF 987654321
using namespace std;

int v, e, start;
int dijkstra[MAX];
vector<pair<int, int>> vertex[MAX];

void solution()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dijkstra[start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < vertex[cur].size(); i++)
		{
			int next = vertex[cur][i].first;
			int n_cost = vertex[cur][i].second;
			if (dijkstra[next] > cost + n_cost)
			{
				dijkstra[next] = cost + n_cost;
				pq.push({ -dijkstra[next], next });
			}
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;
	cin >> v >> e >> start;
	
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back({b,c});
	}
	for (int i = 1; i <= v; i++)
		dijkstra[i] = INF;
	solution();
	for (int i = 1; i <= v; i++)
	{
		if (dijkstra[i] == INF)
			cout << "INF\n";
		else
			cout << dijkstra[i] << "\n";
	}

	return 0;
}