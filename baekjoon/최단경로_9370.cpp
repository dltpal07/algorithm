//https://www.acmicpc.net/problem/9370


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 2001
#define INF 987654321
vector<pair<int, int>> vertex[MAX];
int dijkstra[MAX];
vector<int> dest;
int T, n, m, t;
int s, g, h, a, b, d;


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

int compare(int end)
{
	int c1, c2, c3, c4, c5, min_val;
	for (int i = 1; i <= n; i++)
	{
		dijkstra[i] = INF;
	}
	Dijkstra(s);
	/*for (int i = 1; i <= n; i++)
	{
		cout << i << " " << dijkstra[i] << endl;
	}*/
	c1 = dijkstra[g];
	c2 = dijkstra[h];
	min_val = dijkstra[end];
	for (int i = 1; i <= n; i++)
	{
		dijkstra[i] = INF;
	}
	Dijkstra(g);
	c3 = dijkstra[h];
	c4 = dijkstra[end];

	for (int i = 1; i <= n; i++)
	{
		dijkstra[i] = INF;
	}
	Dijkstra(h);
	c5 = dijkstra[end];
	//cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 <<" "<<min_val<< endl;
	if (c1+c3+c5 == min_val)
	{
		return 1;
	}
	else if (c2 +c3+c4 == min_val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

vector<int> solution()
{
	vector<int> answer;
	for (int i = 0; i < dest.size(); i++)
	{
		if (compare(dest[i]) == 1)
		{
			answer.push_back(dest[i]);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main(void)
{
	
	cin >> T;
	while (T--)
	{
		dest.clear();
		memset(vertex, 0, sizeof(vertex));
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> d;
			vertex[a].push_back({ b,d });
			vertex[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++)
		{
			int tmp;
			cin >> tmp;
			dest.push_back(tmp);
		}
		vector<int> answer = solution();
		for (auto k : answer)
		{
			cout << k << " ";
		}
		cout << endl;
	}
	return 0;
}