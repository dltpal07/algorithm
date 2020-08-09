//https://www.acmicpc.net/problem/5618


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
	int n, a, b, c, answer;
	
	cin >> n;
	if (n == 2)
	{
		cin >> a >> b;
		answer = gcd(a, b);
	}
	else
	{
		cin >> a >> b>>c;
		a = gcd(a, b);
		answer = gcd(a, c);
	}
	for (int i = 1; i <= answer; i++)
	{
		if (answer%i == 0)
		{
			cout << i << endl;
		}
	}
	return 0;
}