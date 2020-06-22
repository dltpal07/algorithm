//https://www.acmicpc.net/problem/12015


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, temp, cnt = 0;
	vector<int> v;
	v.push_back(INT_MIN);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp > v.back())
		{
			v.push_back(temp);
			cnt++;
		}
		else
		{
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
			*low = temp;
		}
	}
	cout << cnt;
	return 0;
}