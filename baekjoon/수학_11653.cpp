//https://www.acmicpc.net/problem/11653


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int N,i=2;
	cin >> N;
	while (1)
	{
		if (N == 1)
			break;
		if (N%i == 0)
		{
			cout << i << "\n";
			N = N / i;
		}
		else
			i++;
	}

	return 0;
}