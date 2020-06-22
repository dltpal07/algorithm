//https://www.acmicpc.net/problem/1655


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int mid = 100000;
priority_queue<int, vector<int>, less<int>> MinQ;
priority_queue<int, vector<int>, greater<int>> MaxQ;

void Balence()
{
	int left = MinQ.size();
	int right = MaxQ.size();
	if (right == left || abs(right - left) == 1)
		return;
	if (left > right)
	{
		while (1)
		{
			if (right + 1 == left || right == left)
				break;
			MaxQ.push(mid);
			right++;
			mid = MinQ.top();
			MinQ.pop();
		}
	}
	else
	{
		while (1)
		{
			if (left + 1 == right || left == right)
				break;
			MinQ.push(mid);
			left++;
			mid = MaxQ.top();
			MaxQ.pop();
		}
	}
}

int ans()
{
	int temp;
	if (MinQ.size() > MaxQ.size())
		temp = MinQ.top();
	else
		temp = MaxQ.top();
	if (temp < mid)
		return temp;
	else
		return mid;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
		{
			mid = num;
			cout << mid << "\n";
			continue;
		}
		if (mid > num)
			MinQ.push(num);
		else
			MaxQ.push(num);
		Balence();
		if (i % 2 == 0)
			cout << mid << "\n";
		else
			cout << ans() << "\n";
	}
	return 0;
}