// https://www.acmicpc.net/problem/11659


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<long long> accum(N+1);
	long long tmp, inter_i, inter_j;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		accum[i] = accum[i - 1] + tmp;
	}
	

	for (int i = 0; i < M; i++)
	{
		cin >> inter_i >> inter_j;
		cout << accum[inter_j] - accum[inter_i - 1] << "\n";
	}
	return 0;
}