//https://www.acmicpc.net/problem/2609


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
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
int main(void)
{
	
	int n, m,i=2,tmp, _min,_max;
	cin >> n >> m;
	if (n > m)
		_min = gcd(n, m);
	else
		_min = gcd(m, n);
	_max = _min * (n / _min)*(m / _min);
	cout << _min << "\n" << _max;
	return 0;
}