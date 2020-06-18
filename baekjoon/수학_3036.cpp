//https://www.acmicpc.net/problem/3036


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (1) 
	{
		if (b == 0)
			break;
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	int n, g;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (r[0] > r[i])
		{
			g = gcd(r[0], r[i]);
		}
		else
		{
			g = gcd(r[i], r[0]);
		}

		cout << r[0] / g << '/' << r[i] / g << "\n";
	}
	return 0;
}