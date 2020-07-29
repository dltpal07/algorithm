https://www.acmicpc.net/problem/1964


#include <iostream>
using namespace std;

const int MAX = 10000001;
int spot[MAX];
int main(void)
{
	int n;
	cin >> n;
	spot[1] = 5;
	for (int i = 2; i <= n; i++)
	{
		spot[i] = (spot[i - 1] + (i + 1) * 3 - 2) % 45678;
	}
	cout << spot[n];
	return 0;
}