// https://www.acmicpc.net/problem/1269

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<long long> A, B;
	long long tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int j = 0; j < M; j++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}
	int summation = A.size() + B.size();
	int union_num = 0;
	sort(A.begin(), A.end());
	int left_idx, right_idx, mid_idx;
	for (int i = 0; i < M; i++)
	{
		left_idx = 0;
		right_idx = A.size() - 1;
		long long target = B[i];
		while (left_idx <= right_idx)
		{
			mid_idx = (left_idx + right_idx) / 2;
			if (A[mid_idx] == target)
			{
				union_num++;
				break;
			}
			else if (A[mid_idx] > target)
			{
				right_idx = mid_idx - 1;
			}
			else
			{
				left_idx = mid_idx + 1;
			}
		}
	}
	if (summation - union_num * 2 > 0)
		cout << summation - union_num * 2;
	else
		cout << 0;
	return 0;
}