//https://www.acmicpc.net/problem/5533


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checked[101][3] = { 0 };

int main(void)
{
	int N;
	cin >> N;
	vector<int> score(N, 0);
	vector<vector<int>> num(N, vector<int>(3));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num[i][j];
			checked[num[i][j]][j]++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (checked[num[i][j]][j] == 1)
			{
				score[i] += num[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << score[i] << endl;
	}
	return 0;
}