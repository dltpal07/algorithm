//https://www.acmicpc.net/problem/1021


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int turn_left(deque<int> q, int n)
{
	int tmp, cnt = 0;
	while (1)
	{
		tmp = q.front();
		if (tmp == n)
		{
			break;
		}
		q.pop_front();
		q.push_back(tmp);
		cnt++;
	}
	return cnt;
}

int turn_right(deque<int> q, int n)
{
	int tmp, cnt = 0;
	while (1)
	{
		tmp = q.front();
		if (tmp == n)
		{
			break;
		}
		tmp = q.back();
		q.pop_back();
		q.push_front(tmp);
		cnt++;
	}
	return cnt;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m, tmp, cnt =0;
	cin >> n >> m;
	vector<int> x(m);
	deque<int> q,a,b;
	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
		
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (turn_left(q, x[i]) < turn_right(q, x[i]))
		{
			while (1)
			{
				tmp = q.front();
				if (tmp == x[i])
				{
					q.pop_front();
					break;
				}
				q.pop_front();
				q.push_back(tmp);
				cnt++;
			}
		}
		else
		{
			while (1)
			{
				tmp = q.front();
				if (tmp == x[i])
				{
					q.pop_front();
					break;
				}
				tmp = q.back();
				q.pop_back();
				q.push_front(tmp);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}