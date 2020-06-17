//https://www.acmicpc.net/problem/4153


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	long long a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if ((pow(a, 2) + pow(b, 2) == pow(c, 2))|| (pow(c, 2) + pow(b, 2) == pow(a, 2))|| (pow(a, 2) + pow(c, 2) == pow(b, 2)))
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	return 0;
}