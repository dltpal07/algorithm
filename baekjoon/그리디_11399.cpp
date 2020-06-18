//https://www.acmicpc.net/problem/11399


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
	int n, m[1000],sum = 0, tmp = 0, last = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
	}
	sort(m, m+n);
	for (int i = 0; i < n; i++)
	{
		sum += m[i] * (n - i);
	}
	
	cout << sum;
	return 0;
}