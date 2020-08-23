//https://www.acmicpc.net/problem/9550


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int t, N, K, cnt;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N >> K;
		cnt = 0;
		vector<int> candy(N);
		for (int j = 0; j < N; j++)
		{
			cin >> candy[j];
		}
		for (int j = 0; j < N; j++)
		{
			cnt += candy[j] / K;
		}
		cout << cnt << "\n";
	}
	return 0;
}