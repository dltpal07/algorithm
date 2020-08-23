//https://www.acmicpc.net/problem/1145


#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	int num[5];
	int perm[10][3] = { {0, 1, 2}, {0, 1, 3}, {0, 1, 4}, {0, 2, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4} };
	long long v[10];
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 10; i++)
	{
		v[i] = lcm(lcm(num[perm[i][0]], num[perm[i][1]]), num[perm[i][2]]);
	}
	sort(v, v + 10);
	cout << v[0];
	return 0;
}