//https://www.acmicpc.net/problem/5086


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		if (b%a == 0)
			cout << "factor" << endl;
		else if (a%b == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}
	return 0;
}