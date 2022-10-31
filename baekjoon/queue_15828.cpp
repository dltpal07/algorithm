// https://www.acmicpc.net/problem/15828

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	deque<int> q;
	bool flag = false;
	int N, tmp, cur_cnt = 0;
	cin >> N;
	while (1)
	{
		cin >> tmp;
		if (tmp == -1)
			break;
		if (tmp == 0)
		{
			q.pop_front();
			cur_cnt--;
		}
		else if (cur_cnt < N)
		{
			q.push_back(tmp);
			cur_cnt++;
		}

	}
	while (!q.empty())
	{
		flag = true;
		cout << q.front() << " ";
		q.pop_front();
	}
	if (!flag)
	{
		cout << "empty";
	}
	return 0;
}