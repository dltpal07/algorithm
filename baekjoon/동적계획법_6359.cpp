//https://www.acmicpc.net/problem/6359


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
	int t, n, x[101] = { 0 };
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		memset(x, 0, sizeof(x));
		x[0] = 1;
		for (int j = 2; j <= n; j++)
		{
			for (int k = 1; j*k <= n; k++)
			{
				x[j*k] = !x[j*k];
			}
		}
		cout << count(x, x + n+1, 0)<<endl;
	}
	return 0;
}