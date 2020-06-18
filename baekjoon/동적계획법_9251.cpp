//https://www.acmicpc.net/problem/9251


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char A[1001], B[1001];
int DP[1001][1001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> A>>B;
	int A_size = strlen(A), B_size = strlen(B);
	for (int i = 1; i <= A_size; i++)
	{
		for (int j = 1; j <= B_size; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}

		} 
	}
	cout << DP[A_size][B_size];
	return 0;
}