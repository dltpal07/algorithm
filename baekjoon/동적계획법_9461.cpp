//https://www.acmicpc.net/problem/9461


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
long long cache[101];
long long get_p(int t)
{
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	for (int i = 4; i <= t; i++)
	{
		cache[i] = cache[i - 3] + cache[i - 2];
	}
	return cache[t];
}
int main(void)
{
	int t = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		cout << get_p(t)<<endl;
	}
	return 0;
}