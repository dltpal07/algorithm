//https://www.acmicpc.net/problem/11053


#include <iostream>
using namespace std;
int DP[10001];
int x[10001];
int n;
int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	int cnt = 0, _max = 0, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (x[i] > x[j])
			{
				DP[i] = MAX(DP[j] + 1, DP[i]);
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (_max < DP[i])
			_max = DP[i];
	}
	cout << _max;
	return 0;
}