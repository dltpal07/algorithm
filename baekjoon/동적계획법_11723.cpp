//https://www.acmicpc.net/problem/11723


#include <iostream>
#include <string>
using namespace std;

int M, tmp, bit;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (str == "add")
		{
			cin >> tmp;
			bit |= (1 << tmp);
		}
		else if (str == "remove")
		{
			cin >> tmp;
			bit &= ~(1 << tmp);
		}
		else if (str == "check")
		{
			cin >> tmp;
			if (bit&(1 << tmp))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "toggle")
		{
			cin >> tmp;
			bit ^= (1 << tmp);
		}
		else if (str == "all")
		{
			bit = (1 << 21) - 1;
		}
		else if (str == "empty")
		{
			bit = 0;
		}
	}
	return 0;
}