//https://www.acmicpc.net/problem/1966


#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	int cnt = 0;
	int t, n, m, tmp;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			q.push({ j, tmp });
			pq.push(tmp);
		}
		while (!q.empty())
		{
			int idx = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value)
			{
				pq.pop();
				cnt++;
				if (idx == m)
				{
					cout << cnt << "\n";
				}
			}
			else
				q.push({ idx, value });
		}
	}
	return 0;
}