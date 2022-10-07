#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	int cnt = 0;
	string str;
	vector<string> s, v;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		s.push_back(str);
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	int left_idx, right_idx, mid_idx;
	for (int i = 0; i < M; i++)
	{
		left_idx = 0;
		right_idx = N - 1;
		string target = v[i];
		while (left_idx <= right_idx)
		{
			mid_idx = (left_idx + right_idx) / 2;
			if (s[mid_idx] == target)
			{
				cnt++;
				break;
			}
			else if (s[mid_idx] < target)
			{
				left_idx = mid_idx + 1;
			}
			else // s[mid_idx] > target
			{
				right_idx = mid_idx - 1;
			}
		}
	}
	cout << cnt;
	
	return 0;
}