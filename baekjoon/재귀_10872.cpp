//https://www.acmicpc.net/problem/10872


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int factorial(int n)
{
	
	if (n == 1)
	{
		return 1;
	}
	if (n == 0)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

int main(void)
{
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}