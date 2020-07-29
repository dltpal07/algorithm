//https://www.acmicpc.net/problem/4504


#include <iostream>
using namespace std;

int main(void)
{
	int n, tmp;
	cin >> n;
	while (1)
	{
		cin >> tmp;
		if (tmp == 0)
			break;
		if (tmp%n == 0)
			cout << tmp << " is a multiple of " << n << ".\n";
		else
			cout << tmp << " is NOT a multiple of " << n << ".\n";
	}
	return 0;
}

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