//https://www.acmicpc.net/problem/1427


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	vector<int> A;
	cin >> N;
	while (1)
	{
		if (N == 0)
		{
			break;
		}
		A.push_back(N % 10);
		N = N / 10;
	}
	sort(A.begin(), A.end(), greater<int>());
	for (auto x : A)
	{
		cout << x;
	}
	return 0;
}