//https://www.acmicpc.net/problem/13458


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	long long N, A, B, cnt = 0;
	cin >> N;
	vector<double> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	cin >> A >> B;
	for (int i = 0; i < N; i++)
	{
		cnt++;
		v[i] -= A;
		if (v[i] > 0)
		{
			cnt += ceil(v[i] / B);
		}
	}
	cout << cnt;
	return 0;
}