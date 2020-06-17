//https://www.acmicpc.net/problem/9663


#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
#define MAX 11
int N;
int col[15];
int result = 0;

bool promising(int cnt)
{
	for (int j = 0; j < cnt; j++) 
	{
		if (col[j] == col[cnt] || abs(col[cnt] - col[j]) == (cnt - j))
			return false;
	}
	return true;
}

void N_Queen(int cnt)
{
	if (cnt == N)
	{
		result += 1;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[cnt] = i;
			if (promising(cnt))
			{
				N_Queen(cnt + 1);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	N_Queen(0);
	cout << result << endl;
	return 0;
}