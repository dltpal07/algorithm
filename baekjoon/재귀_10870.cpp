//https://www.acmicpc.net/problem/10870


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;


int Fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}
	return Fibo(n - 1) + Fibo(n - 2);
	
}

int main(void)
{
	int n;
	cin >> n;
	cout << Fibo(n);
	return 0;
}