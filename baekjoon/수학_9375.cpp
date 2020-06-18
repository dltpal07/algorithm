//https://www.acmicpc.net/problem/9375


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string a, b;
	int t, n, p, sum=0, mul = 1;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<string> x;
		vector<pair<string, int>> y;
		mul = 1;
		for (int j = 0; j < n; j++)
		{
			cin >> a >> b;
			if (count(x.begin(), x.end(), b) == 0)
			{
				x.push_back(b);
				y.push_back({ b,1 });
			}
			else
			{
				p = distance(x.begin(), find(x.begin(), x.end(), b));
				y[p].second++;
			}
		}
		for (int j = 0; j < y.size(); j++)
		{
			mul *= (y[j].second+1);
		}
		
			cout << mul-1 << "\n";
		
		
	}
	return 0;
}