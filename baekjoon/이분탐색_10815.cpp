// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	long long M, N, tmp, left_idx, right_idx, mid;
	vector<long long> v, compare_v;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		compare_v.push_back(tmp);
	}
	
	for (int i = 0; i < N; i++)
	{
		long long target = compare_v[i];
		left_idx = 0;
		right_idx = v.size();
		int flag = 0;
		while (left_idx <= right_idx)
		{
			mid = (left_idx + right_idx) / 2;
			if (v[mid] == target)
			{
				flag = 1;
				cout << "1 ";
				break;
			}
			else if (v[mid]> target)
			{
				right_idx = mid - 1;
			}
			else
			{
				left_idx = mid + 1;
			}
		}
		if (flag == 0)
			cout << "0 ";
		
	}
	return 0;
}