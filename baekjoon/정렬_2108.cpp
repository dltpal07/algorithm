//https://www.acmicpc.net/problem/2108


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <cmath>
using namespace std;

int get_aver(vector<int> x)
{
	int s = 0;
	for (int i = 0; i < x.size(); i++)
	{
		s += x[i];
	}
	return round(s / (double)x.size());
}

int get_middle(vector<int> x)
{
	return x[x.size() / 2];
}

int get_range(vector<int> x)
{
	return x[x.size() - 1] - x[0];
}

int get_max_qtt(vector<int> x)
{
	vector<pair<int, int>> result;
	int plus[4001] = { 0 }, minus[4001] = { 0 }, zero = 0, max = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] > 0)
		{
			plus[x[i]]++;
		}
		else if (x[i] < 0)
		{
			minus[-(x[i])]++;
		}
		else
		{
			zero++;
		}
	}
	for (int i = 4000; i >=1; i--)
	{
		if (max < minus[i])
		{
			result.clear();
			max = minus[i];
			result.push_back({ -i,max });
		}
		else if (max == minus[i])
		{
			max = minus[i];
			result.push_back({ -i, max });
		}
	}
	if (max < zero)
	{
		result.clear();
		max = zero;
		result.push_back({ 0, max });
	}
	else if (max == zero)
	{
		max = zero;
		result.push_back({ 0,max });
	}
	for (int i = 1; i <= 4000; i++)
	{
		if (max < plus[i])
		{
			result.clear();
			max = plus[i];
			result.push_back({ i,max });
		}
		else if (max == plus[i])
		{
			max = plus[i];
			result.push_back({ i, max });
		}
	}
	
	if (result.size() == 1)
	{
		return result[0].first;
	}
	else
	{
		return result[1].first;
	}
	
}

int main(void)
{
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	cout << get_aver(x)<<"\n";
	cout << get_middle(x)<<"\n";
	cout << get_max_qtt(x) << "\n";
	cout << get_range(x) << "\n";
	return 0;
}