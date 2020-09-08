//https://www.acmicpc.net/problem/1373


#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	string str;
	deque<int> q;
	cin >> str;
	int flag = 0;
	int bi = 1;
	int tmp = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (flag == 3)
		{
			flag = 0;
			bi = 1;
			q.push_back(tmp);
			tmp = 0;
		}
		flag++;
		tmp += (str[i] - '0') * bi;
		bi *= 2;
		if (i == 0)
		{
			q.push_back(tmp);
		}

	}
	while (!q.empty())
	{
		cout << q.back();
		q.pop_back();
	}
	return 0;
}