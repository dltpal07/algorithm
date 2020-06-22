//https://www.acmicpc.net/problem/1300


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, k, result=-1;
	cin >> N >> k;
	int low = 1, high = k;
	while (low <= high)
	{
		int cnt = 0;
		int mid = (low + high) / 2;
		for (int i = 1; i <= N; i++)
		{
			cnt += min(mid / i, N);
		}
		if (cnt < k)
		{
			low = mid + 1;
		}
		else
		{
			result = mid;
			high = mid - 1;
		}
		
	}
	cout << result;
	return 0;
}