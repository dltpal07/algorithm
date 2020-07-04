https://www.acmicpc.net/problem/1504


#include <iostream>
#include <queue>
#include <vector>

#define MAX 20001
#define INF 987654321
using namespace std;

int v, e, x, y, answer;
int dijkstra[MAX];
vector<pair<int, int>> vertex[MAX];

int Min(int A, int B)
{
	if (A < B)
		return A;
	else
		return B;
}

void Dijkstra(int start)
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

void solution()
{
	bool flag1 = true, flag2 = true;
	for (int i = 1; i <= v; i++)
		dijkstra[i] = INF;
	Dijkstra(1);
	int route1 = dijkstra[x];
	int route2 = dijkstra[y];
	if (route1 == INF)
		flag1 = false;
	if (route2 == INF)
		flag2 = false;

	for (int i = 1; i <= v; i++)
		dijkstra[i] = INF;
	Dijkstra(x);
	if (flag1 == true)
		route1 = route1 + dijkstra[y];
	if (flag2 == true)
		route2 = route2 + dijkstra[y];

	for (int i = 1; i <= v; i++)
		dijkstra[i] = INF;
	Dijkstra(y);
	if (flag1 == true)
		route1 += dijkstra[v];
	
	for (int i = 1; i <= v; i++)
		dijkstra[i] = INF;
	Dijkstra(x);
	if (flag2 == true)
		route2 += dijkstra[v];

	if (flag1 == false && flag2 == false)
		answer = -1;
	else
	{
		answer = Min(route1, route2);
	}
	if (answer == INF)
		answer = -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;
	cin >> v >> e;
	
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back({ b,c });
		vertex[b].push_back({ a,c });
	}
	
	cin >> x >> y;

	solution();
	cout << answer;
	

	return 0;
}