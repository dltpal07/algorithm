//https://www.acmicpc.net/problem/2810


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, k, cnt = 1;;
	cin >> N;

	vector<char> seat(N);
	for (int i = 0; i < N; i++)
	{
		cin >> seat[i];
	}
	k = 0;
	while (k<N)
	{
		if (seat[k] == 'S')
		{
			cnt++;
			k++;
		}
		else if (seat[k] == 'L'&&seat[k + 1] == 'L')
		{
			cnt++;
			k += 2;
		}
	}
	if (N < cnt)
	{
		cout << N;
	}
	else
	{
		cout << cnt;
	}
	return 0;
}