//https://www.acmicpc.net/problem/1213


#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	string str;
	deque<char> q1, q2;
	cin >> str;
	int a[26] = { 0 }, idx = 0;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
	{
		a[str[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] % 2 != 0)
		{
			cnt++;
			idx = i;
		}
	}
	if (cnt > 1)
	{
		cout << "I'm Sorry Hansoo";
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < a[i] / 2; j++)
			{
				q1.push_back((char)('A' + i));
				q2.push_back((char)('A' + i));

			}
		}
		while (!q1.empty())
		{
			cout << q1.front();
			q1.pop_front();
		}
		if(cnt == 1)
			cout << (char)('A' + idx);
		while (!q2.empty())
		{
			cout << q2.back();
			q2.pop_back();
		}
	}
	return 0;
}