//https://www.acmicpc.net/problem/10610


#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	priority_queue<char> pq;
	cin >> str;
	long long total = 0;
	for (int i = 0; i < str.size(); i++)
	{
		total += str[i] - '0';
		pq.push(str[i]);
	}
	if (find(str.begin(), str.end(), '0') == str.end() || total % 3 != 0)
	{
		cout << "-1";
	}
	else
	{
		while (!pq.empty())
		{
			cout << pq.top();
			pq.pop();
		}
	}
	return 0;
}