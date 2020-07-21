//https://www.acmicpc.net/problem/1357


#include <iostream>

using namespace std;

int reverse(int x)
{
	int len_x = x, rev_x = 0, e = 1;
	while (len_x > 0)
	{
		len_x = len_x / 10;
		e*=10;
	}
	while (x > 0)
	{
		rev_x += x % 10 * e;
		e /= 10;
		x = x / 10;
	}
	return rev_x/10;
}

int main(void)
{
	int X, Y;
	cin >> X >> Y;
	
	cout << reverse(reverse(X) + reverse(Y));
	return 0;;
}