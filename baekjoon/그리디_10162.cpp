//https://www.acmicpc.net/problem/10162


#include <iostream>

using namespace std;

int main(void)
{
	int T, a = 0, b = 0, c = 0;
	cin >> T;
	if (T >= 300)
	{
		
		a = T / 300;
		T %= 300;
	}
	if (T >= 60)
	{
		b = T / 60;
		T %= 60;
	}
	if (T >= 10)
	{
		c = T / 10;
		T %= 10;
	}
	if (T == 0)
	{
		cout << a<<" "<<b<<" "<<c;
	}
	else
	{
		cout << -1;
	}
	return 0;
}