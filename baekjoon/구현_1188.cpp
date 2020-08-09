//https://www.acmicpc.net/problem/1188


#include <iostream>

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
	int N, M, ms;
	cin >> N >> M;
	ms = gcd(N, M);
	N /= ms;
	M /= ms;
	cout << (M - 1)*ms;
	return 0;
}