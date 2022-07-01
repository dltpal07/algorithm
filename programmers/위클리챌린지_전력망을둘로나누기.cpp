// https://programmers.co.kr/learn/courses/30/lessons/86971

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int wire_graph[101][101] = { 0, };
int checked[101] = { 0, };
int BFS(int cur_vertex, int n)
{
	int cnt;
	queue<int> q;
	q.push(cur_vertex);
	checked[cur_vertex] = 1;
	cnt = 1;
	while (!q.empty())
	{
		int cur_i = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (checked[i] == 0 && wire_graph[cur_i][i] == 1)
			{
				checked[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	return cnt;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = -1;
	int cnt1, cnt2;
	priority_queue<int> pq;
	for (int i = 0; i < wires.size(); i++)
	{
		wire_graph[wires[i][0]][wires[i][1]] = 1;
		wire_graph[wires[i][1]][wires[i][0]] = 1;
	}
	
	for (int i = 0; i < wires.size(); i++)
	{
		cnt1 = 0;
		cnt2 = 0;
		memset(checked, 0, sizeof(int) * 101);
		wire_graph[wires[i][0]][wires[i][1]] = 0;
		wire_graph[wires[i][1]][wires[i][0]] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (checked[i] == 0)
			{
				if (cnt1 == 0)
					cnt1 = BFS(i, n);
				else
					cnt2 = BFS(i, n);
			}
		}
		pq.push(-1 * abs(cnt1 - cnt2));
		wire_graph[wires[i][0]][wires[i][1]] = 1;
		wire_graph[wires[i][1]][wires[i][0]] = 1;
	}

	answer = pq.top() * -1;
	return answer;
}

int main(void)
{
	int n1 = 9, n2 = 4, n3 = 7;
	vector<vector<int>> wires1 = { {1,3} ,{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
	vector<vector<int>> wires2 = { {1, 2}, {2, 3}, {3, 4} };
	vector<vector<int>> wires3 = { {1,2} ,{2,7},{3,7},{3,4},{4,5},{6,7} };
	int answer = solution(n1, wires1);
	cout << answer;
	return 0;
}
