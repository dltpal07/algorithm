//https://www.acmicpc.net/problem/1904


#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 15746;
const int MAX = 1000000;

int N;
int cache[MAX + 1];
int kindsOfBinary(void)
{
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		cache[i] = (cache[i - 2] + cache[i - 1])%MOD;
	}
	return cache[N] % MOD;
}

int main(void)
{
	cin >> N;
	cout << kindsOfBinary();
	return 0;
}