//https://www.acmicpc.net/problem/2903


#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, x[15], tmp = 1;
	cin >> n;
	x[0] = 2;
	
	for (int i = 1; i <= n; i++)
	{
		x[i] = x[i - 1] + tmp;
		tmp *= 2;
	}
	cout << x[n] * x[n];
	return 0;
}