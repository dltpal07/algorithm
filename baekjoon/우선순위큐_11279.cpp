//https://www.acmicpc.net/problem/11279


#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0 && pq.empty())
		{
			cout << 0 << "\n";
		}
		else if (num == 0)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
		else
			pq.push(num);
	}
	return 0;
}