//https://www.acmicpc.net/problem/2805


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

long long N, M;
long long tree[MAX];

bool possible(long long len)
{
	long long all_len = 0;
	for (int i = 0; i < N; i++)
	{
		if(tree[i]-len>=0)
			all_len += tree[i] - len;
	}
	if (all_len >= M)
		return true;
	return false;
}

int main(void)
{
	long long high, low,mid,Max=0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		high = max(high, tree[i]);
	}
	low = 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (possible(mid))
		{
			if (Max < mid)
				Max = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << Max;
	return 0;
}