//https://www.acmicpc.net/problem/10409


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, T, tmp, answer = 0;
	cin >> n >> T;
	vector<int> v(n);
	vector<long long> sum(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sum[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + v[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (sum[i] > T)
		{
			answer = i;
			break;
		}
		answer = i + 1;
	}
	cout << answer;
	return 0;
}