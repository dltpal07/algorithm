//https://www.acmicpc.net/problem/1620

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
	vector<pair<string, int>> v;
	vector<string> origin;
	string str;
	int left_idx, right_idx, mid_idx;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v.push_back({ str, i + 1 });
		origin.push_back(str);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9')
		{
			int tmp_num = stoi(str);
			cout << origin[tmp_num - 1] << "\n";
		}
		else
		{
			left_idx = 0;
			right_idx = v.size();
			while (left_idx <= right_idx)
			{
				mid_idx = (left_idx + right_idx) / 2;
				if (v[mid_idx].first == str)
				{
					cout << v[mid_idx].second << "\n";
					break;
				}
				else if (v[mid_idx].first > str)
				{
					right_idx = mid_idx - 1;
				}
				else
				{
					left_idx = mid_idx + 1;
				}
			}
		}
	}
	return 0;
}