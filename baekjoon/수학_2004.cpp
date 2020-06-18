//https://www.acmicpc.net/problem/2004


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

pair<long long, long long> numOfZero(long long N)
{
	long long two = 0, five = 0;
	for (long long i = 2; i <= N; i *= 2)
	{
		two += N / i;
	}
	for (long long i = 5; i <= N; i *= 5)
	{
		five += N / i;
	}
	return { two, five };
}

int main(void)
{
	long long n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> v(3);
	v[0] = numOfZero(n);
	v[1] = numOfZero(m);
	v[2] = numOfZero(n - m);
	cout << min(v[0].first - v[1].first - v[2].first, v[0].second - v[1].second - v[2].second);
	return 0;
}