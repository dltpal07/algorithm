// https://www.acmicpc.net/problem/2559


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	long long tmp, max_val = -987654321;
	vector<long long> accum(N + 1);
	accum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		accum[i] += accum[i - 1] + tmp;
	}
	for (int i = K; i <= N; i++)
	{
		long long comp = accum[i] - accum[i - K];
		if (max_val < comp)
			max_val = comp;
	}
	cout << max_val;
	return 0;
}