//https://www.acmicpc.net/problem/2231


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int get_sum(int n)
{
	int sum = 0;
	sum += n;
	while (1)
	{
		if (n == 0)
			break;
		sum += n % 10;
		n = n / 10;

	}
	return sum;
}

int main(void)
{
	bool isPrint = false;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (get_sum(i) == N)
		{
			cout << i;
			isPrint = true;
			break;
		}
	}
	if (!isPrint)
	{
		cout << 0;
	}
	return 0;
}