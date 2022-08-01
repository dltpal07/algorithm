// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>

using namespace std;

long long comb[31][31] = { 0, };

int main(void)
{
	int T, n, k;
	cin >> T;
	comb[0][0] = 1;
	comb[1][0] = 1;
	comb[1][1] = 1;
	for (int i = 2; i <= 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 or j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}

	}

	for (int t = 0; t < T; t++)
	{
		cin >> k >> n;
		cout << comb[n][k] << endl;
	}
	return 0;
}