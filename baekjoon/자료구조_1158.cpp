//https://www.acmicpc.net/problem/1158


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void)
{
	bool flag = true;
	deque<int> front_q, back_q;
	vector<int> answer;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		front_q.push_back(i);
	}
	while (1)
	{
		if (answer.size() == N)
			break;
		
		for (int i = 0; i < K - 1; i++)
		{
			if (front_q.size() == 0)
			{
				flag = false;
			}
			else if (back_q.size() == 0)
			{
				flag = true;
			}
			if (flag)
			{
				int x = front_q.front();
				back_q.push_back(x);
				front_q.pop_front();
			}
			else
			{
				int x = back_q.front();
				front_q.push_back(x);
				back_q.pop_front();
			}
		}

		if (front_q.size() == 0)
		{
			flag = false;
		}
		else if (back_q.size() == 0)
		{
			flag = true;
		}
		if (flag)
		{
			answer.push_back(front_q.front());
			front_q.pop_front();
		}
		else
		{
			answer.push_back(back_q.front());
			back_q.pop_front();
		}
		
	}
	cout << "<";
	for (int i=0;i<N-1;i++)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[N - 1] << ">";
	return 0;
}