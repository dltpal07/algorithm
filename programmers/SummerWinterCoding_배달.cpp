//https://programmers.co.kr/learn/courses/30/lessons/12978


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 51
int solution(int N, vector<vector<int>> road, int k)
{
	int answer = 0;
	vector<int> dijkstra(MAX, 987654321);
	vector<pair<int, int>> vertex[MAX];

	for (int i = 0; i < road.size(); i++)
	{
		vertex[road[i][0]].push_back({ road[i][1], road[i][2]});
		vertex[road[i][1]].push_back({ road[i][0], road[i][2] });
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	dijkstra[1] = 0;
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
	
	
	for (int i = 1; i <= N; i++)
	{
		if (dijkstra[i] <= k)
			answer++;
	}
	return answer;
}

int main(void)
{
	int N1 = 5, N2 = 6, K1 = 3, K2 = 4;
	vector<vector<int>> road1 = {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}},
		road2 = {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}};
	cout << solution(N2, road2, K2);
	return 0;
}