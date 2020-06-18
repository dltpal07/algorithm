//https://www.acmicpc.net/problem/11054


#include <iostream>
#include <vector>

using namespace std;
int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	
	int _max=0,n, x[1000], l[1000], b_l[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		l[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (x[i] > x[j])
			{
				l[i] = MAX(l[i], l[j] + 1);
			}
		}
	}
	for (int i = n-1; i >=0; i--)
	{
		b_l[i] = 1;
		for (int j = n-1; j > i; j--)
		{
			if (x[i] > x[j])
			{
				b_l[i] = MAX(b_l[i], b_l[j] + 1);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (_max < l[i] + b_l[i]-1)
		{
			_max = l[i] + b_l[i]-1;
		}
	}
	cout << _max;
	return 0;
}
