//https://www.acmicpc.net/problem/1652


#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
int N;
string room[MAX];

int main(void)
{
	int answer1 = 0, answer2 = 0, cnt;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> room[i];
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (room[i][j] == '.')
			{
				cnt++;
			}
			else if (room[i][j] == 'X' && cnt >= 2)
			{
				answer1++;
				cnt = 0;
			}
			else if (room[i][j] == 'X')
			{
				cnt = 0;
			}
		}
		if (cnt >= 2)
		{
			answer1++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (room[j][i] == '.')
			{
				cnt++;
			}
			else if (room[j][i] == 'X' && cnt >= 2)
			{
				answer2++;
				cnt = 0;
			}
			else if (room[j][i] == 'X')
			{
				cnt = 0;
			}
		}
		if (cnt >= 2)
			answer2++;
	}
	cout << answer1 << " " << answer2;
	return 0;
}