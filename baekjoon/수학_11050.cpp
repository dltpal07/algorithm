//https://www.acmicpc.net/problem/11050


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


int main(void)
{
	int n, k,a=1,b=1;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		a *= (n - i);
		b *= (k - i);
	}
	cout << a / b;
	return 0;
}