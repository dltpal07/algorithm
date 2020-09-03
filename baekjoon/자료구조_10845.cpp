//https://www.acmicpc.net/problem/10845


#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main(void)
{
	int N;
	string tmp;
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (tmp == "pop")
		{
			if (!q.empty())
			{
				int x;
				x = q.front();
				q.pop();
				cout << x << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (tmp == "size")
		{
			cout << q.size() << "\n";
		}
		else if (tmp == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (tmp == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front()<<"\n";
			}
		}
		else if (tmp == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}