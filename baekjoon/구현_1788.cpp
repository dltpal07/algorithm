//https://www.acmicpc.net/problem/1788


#include <iostream>
#include <cmath>
using namespace std;
long long fibo[1000001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, ans;
	cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= abs(n); i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000000;
	}
	
	
	if (n == 0)
	{
		cout << 0 << "\n";
	}
	else if (n<0 && n % 2 == 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << 1 << "\n";
	}
	
	
	cout << fibo[abs(n)];
	return 0;
}