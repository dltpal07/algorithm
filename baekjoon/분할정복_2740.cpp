//https://www.acmicpc.net/problem/2740


#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

long long pow(int a, int b, int c)
{
	if (b == 1)
		return a;
	else
	{
		long long tmp = pow(a-1, b / 2, c);
		if (b % 2 == 1)
		{
			return (tmp * tmp % c * a) % c;
		}
		else
			return tmp * tmp % c;

	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m, n,k, r=0;
	cin >> n >> m;
	vector<vector<int>> x, y, z;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp(m);
		for (int j = 0; j < m; j++)
		{
			cin >> tmp[j];
		}
		x.push_back(tmp);
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		vector<int> tmp(k);
		for (int j = 0; j < k; j++)
		{
			cin >> tmp[j];
		}
		y.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < k; j++)
		{
			r = 0;
			for (int t = 0; t < m; t++)
			{
				r += x[i][t] * y[t][j];
			}
			tmp.push_back(r);
		}
		z.push_back(tmp);
	}
	for (auto u : z)
	{
		for (auto _u : u)
		{
			cout << _u << " ";
		}
		cout << endl;
	}
	return 0;
}