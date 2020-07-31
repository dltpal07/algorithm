//https://www.acmicpc.net/problem/1834


#include <iostream>

using namespace std;

int main(void)
{
	long long x;
	long long sum = 0;
	cin >> x;
	for (long long i = 1; i < x; i++)
	{
		sum += i * x + i;
	}
	cout << sum;
	return 0;
}