//https://www.acmicpc.net/problem/18258


#include <iostream>
#include <vector>
#include <string>
using namespace std;
int stack[2000000] = { 0 };
int st=0, ed = 0;


int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> tmp;
			stack[ed] = tmp;
			ed++;
		}
		else if (str == "pop")
		{
			if (ed - st == 0)
			{
				cout << "-1\n";
			}
			else
			{
				int tmp = stack[st];
				stack[st] = 0;
				st++;
				cout << tmp << "\n";
			}
		}
		else if (str == "size")
		{
			cout << ed - st << "\n";
		}
		else if (str == "empty")
		{
			if (ed - st == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (ed - st == 0)
				cout << "-1\n";
			else
				cout << stack[st] << "\n";
		}
		else if (str == "back")
		{
			if (ed - st == 0)
				cout << "-1\n";
			else
				cout << stack[ed - 1] << "\n";
		}
	}
	return 0;
}