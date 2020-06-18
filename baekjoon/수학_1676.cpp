//https://www.acmicpc.net/problem/1676


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n, tcnt=0, fcnt=0, tmp;
	cin >> n;
	for (int i = n; i >=1; i--)
	{
		tmp = i;
		if (tmp == 0)
			break;
		while (1)
		{
			if (tmp % 2 == 0)
			{
				tmp /= 2;
				tcnt++;
			}
			else
				break;
		}
		while (1)
		{
			if (tmp == 0)
				break;
			if (tmp % 5 == 0)
			{
				tmp /= 5;
				fcnt++;
			}
			else
				break;
		}

	}
	cout << min(tcnt, fcnt);
	return 0;
}