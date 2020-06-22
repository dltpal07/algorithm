//https://www.acmicpc.net/problem/1629


#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

long long pow(int a, int b, int c)
{
	if (b == 1)
		return a;
	else
	{
		long long tmp = pow(a, b / 2, c);
		if (b % 2 == 1)
		{
			return (tmp * tmp % c * a) % c;
		}
		else
			return tmp * tmp % c;

	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << pow(a%c, b, c) << "\n";
	return 0;
}