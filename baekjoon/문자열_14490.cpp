//https://www.acmicpc.net/problem/14490


#include <iostream>
#include <string>
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

int main(void)
{
	string str, a = "", b = "";
	bool flag = true;
	long long n1, n2, div;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ':')
		{
			flag = false;
			continue;
		}
		if (flag)
		{
			a += str[i];
		}
		else
		{
			b += str[i];
		}
		
	}
	n1 = stol(a);
	n2 = stol(b);
	div = gcd(n1, n2);

	cout << n1/div << ":" << n2/div;
	return 0;
}