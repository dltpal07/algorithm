//https://www.acmicpc.net/problem/1541


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	bool cnt = false, isNeg =false;
	int st = 0, ed = 0,num, sum = 0;
	string pl;
	cin >> pl;
	for (int i = 0; i < pl.size(); i++)
	{
		if (pl[i] != '+'&&pl[i] != '-')
		{
			if (cnt)
			{
				ed = i;
			}
			else
			{
				st = i;
				cnt = true;
			}
		}
		else
		{
			cnt = false;
			num = atoi(pl.substr(st,ed-st+1).c_str());
			if ((st - 1) >= 0)
			{
				if (pl[st - 1] == '+' && isNeg==false)
					sum += num;
				else
				{
					isNeg = true;
					sum -= num;
				}
			}
			else
			{
				sum += num;
			}
		}
	}
	num = atoi(pl.substr(st, ed - st + 1).c_str());
	if ((st - 1) >= 0)
	{
		if ((pl[st - 1] == '+')&& (isNeg == false))
			sum += num;
		else
			sum -= num;
	}
	else
	{
		sum += num;
	}
	cout << sum;
	return 0;
}