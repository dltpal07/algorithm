//https://www.acmicpc.net/problem/2161


#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	queue<int> q;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	while (N>1)
	{
		N--;
		cout << q.front()<<" ";
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.back();
	return 0;
}