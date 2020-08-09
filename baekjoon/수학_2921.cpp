//https://www.acmicpc.net/problem/2921


#include <iostream>

using namespace std;

int x[1001];

int main(void)
{
	int N;
	cin >> N;
	x[1] = 3;
	for (int i = 2; i <= N; i++)
	{
		x[i] = x[i - 1] + (i+1)*(i + 2 * i) / 2;
	}
	cout << x[N];
	return 0;
}