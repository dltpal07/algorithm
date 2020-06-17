//https://www.acmicpc.net/problem/7568


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N, cnt = 0;
	cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first>>A[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (A[i].first < A[j].first && A[i].second < A[j].second)
			{
				cnt++;
			}
		}
		cout << cnt + 1 << " ";
	}
	return 0;
}