//https://www.acmicpc.net/problem/1735


#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	long long a_bottom, a_top, b_bottom, b_top, g, l, sum;
	cin >> a_top >> a_bottom;
	cin >> b_top >> b_bottom;
	g = gcd(a_bottom, b_bottom);
	a_top *= ((b_bottom) / g);
	b_top *= ((a_bottom) / g);
	l = a_bottom * b_bottom / g;
	sum = a_top + b_top;
	g = gcd(sum, l);
	cout << sum / g << " " << l / g;
	return 0;
}