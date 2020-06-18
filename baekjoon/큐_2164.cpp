//https://www.acmicpc.net/problem/2164


#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> q;
	int n, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (1)
	{
		if (q.size() == 1)
			break;
		q.pop();
		if (q.size() == 1)
			break;
		tmp = q.front();
		q.pop();
		q.push(tmp);
		
	}
	cout << q.front();
	return 0;
}