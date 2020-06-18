//https://www.acmicpc.net/problem/1037


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	long long n;
	cin >> n;
	vector<long long> num(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	if (num.size() % 2 == 0)
	{
		cout << num[0] * num[n - 1];
	}
	else
	{
		cout << num[n / 2] * num[n / 2];
	}

	return 0;
}