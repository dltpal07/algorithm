//https://www.acmicpc.net/problem/10539


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long arr[100], ex, dp[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = arr[0];
	
	for (int i = 1; i < n; i++)
	{
		dp[i] = arr[i] * (i + 1) - (arr[i - 1] * (i));
	}
	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	return 0;
}