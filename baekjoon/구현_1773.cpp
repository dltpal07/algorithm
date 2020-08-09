//https://www.acmicpc.net/problem/1773


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checked[2000001] = { 0 };

int main(void)
{
	int N, C, answer=0, cm;
	cin >> N >> C;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < N; i++)
	{
		int j = 1;
		while (1)
		{
			if (v[i] * j > C)
				break;
			checked[v[i] * j] = 1;
			j++;
		}
	}
	cout << count(checked, checked + C+1, 1);
	return 0;
}