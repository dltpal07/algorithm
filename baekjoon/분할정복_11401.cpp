//https://www.acmicpc.net/problem/11401


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
long long n, k;
long long p = 1000000007;
long long fac[4000001];

long long power(long long n, long long k)
{
	if (k == 0)
		return 1;
	long long tmp = power(n, k / 2);
	long long rst = tmp * tmp%p;
	if (k % 2 == 1)
		rst = rst * n%p;
	return rst;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= 4000000; i++)
	{
		fac[i] = fac[i - 1] * i%p;

	}
	long long ret = power(fac[n - k], p - 2)*fac[n] % p;
	ret = ret * power(fac[k], p - 2) % p;
	cout << ret;
	return 0;
}