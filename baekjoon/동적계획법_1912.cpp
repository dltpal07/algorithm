//https://www.acmicpc.net/problem/1912


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, num[100000], DP[100000];

int main(void)
{
	int result = -1001;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	DP[0] = num[0];
	for (int i = 1; i < n; i++)
	{
		DP[i] = max(num[i], DP[i - 1] + num[i]);
	}
	for (int i = 0; i < n; i++)
	{
		result = max(result, DP[i]);
	}
	cout << result;
	return 0;
}