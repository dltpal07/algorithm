//https://www.acmicpc.net/problem/2110


#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 200000;

int N, C;
int house[MAX];

bool possible(int dist)
{
	int cnt = 1;
	int prev = house[0];
	for (int i = 1; i < N; i++)
	{
		if (house[i] - prev >= dist)
		{
			cnt++;
			prev = house[i];
		}
	}
	if (cnt >= C)
		return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int low, high, result = 0,mid;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}
	sort(house, house + N);
	low = 1;
	high = house[N - 1]-house[0];
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (possible(mid))
		{
			result = max(result, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << result;
	
	return 0;
}