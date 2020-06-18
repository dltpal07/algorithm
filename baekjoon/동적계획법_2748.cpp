//https://www.acmicpc.net/problem/2748


#include <iostream>

using namespace std;
long long D[91];
int n;

long long fibo(int n, long long D[90])
{
	D[0] = 0;
	D[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		D[i] = D[i - 1] + D[i - 2];
	}
	return D[n];
}
int main(void)
{
	
	cin >> n;
	cout << fibo(n,D);
	return 0;
}