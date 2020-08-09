//https://www.acmicpc.net/problem/2167


#include <iostream>

using namespace std;
int x[301][301];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, t, a, b, c, d;
	
	long long sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> x[i][j];
		}
	}
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d;
		sum = 0;
		for (int i = a; i <= c; i++)
		{
			
			for (int j = b; j <= d; j++)
			{
				sum += x[i][j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}