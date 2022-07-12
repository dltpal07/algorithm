// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<string> not_hear, not_see, not_hear_see;
	int cnt = 0;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		not_hear.push_back(tmp);
	}
	sort(not_hear.begin(), not_hear.end());
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		not_see.push_back(tmp);
	}
	int left_idx, right_idx, mid_idx;
	for (int i = 0; i < M; i++)
	{
		left_idx = 0;
		right_idx = not_hear.size();
		string target = not_see[i];
		while (left_idx <= right_idx)
		{
			mid_idx = (left_idx + right_idx) / 2;
			if (not_hear[mid_idx] == target)
			{
				cnt++;
				not_hear_see.push_back(target);
				break;
			}
			else if (not_hear[mid_idx] > target)
			{
				right_idx = mid_idx - 1;
			}
			else
			{
				left_idx = mid_idx + 1;
			}
		}
	}
	sort(not_hear_see.begin(), not_hear_see.end());
	cout << cnt << endl;
	for (auto x : not_hear_see)
	{
		cout << x << endl;
	}
	return 0;
}