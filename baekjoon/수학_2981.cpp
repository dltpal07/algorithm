//https://www.acmicpc.net/problem/2981


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int GCD(int a, int b)
{
	if (a%b == 0)
	{
		return b;
	}
	return GCD(b, a%b);
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int gcd = x[1] - x[0];
	for (int i = 2; i < n; i++)
	{
		gcd = GCD(gcd, x[i] - x[i - 1]);
	}
	vector<int> result;
	for (int i = 2; i*i <= gcd; i++)
	{
		if (gcd%i == 0)
		{
			result.push_back(i);
			result.push_back(gcd / i);
		}
	}
	result.push_back(gcd);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}