//https://www.acmicpc.net/problem/2156


#include <iostream>
using namespace std;
int DP[10001];
int x[10001];
int n;
int MAX(int a, int b, int c)
{
	return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	DP[1] = x[1];
	DP[2] = x[1] + x[2];
	for (int i = 3; i <= n; i++)
	{
		DP[i] = MAX(DP[i - 1], DP[i - 2] + x[i], DP[i - 3] + x[i - 1] + x[i]);
	}
	cout << DP[n];
	return 0;
}