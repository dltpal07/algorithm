//https://www.acmicpc.net/problem/11047


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
	int n, k, m[10], cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (k == 0)
			break;
		if (m[i] > k)
			continue;
		cnt += k / m[i];
		k -= (k / m[i])*m[i];
	}
	cout << cnt;
	return 0;
}