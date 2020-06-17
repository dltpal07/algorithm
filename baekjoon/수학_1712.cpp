#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

int main(void)
{
	long long A, B, C, n = 1;
	cin >> A >> B >> C;
	
	if (B>=C)
	{
		cout << "-1\n";
	}
	else
	{
		cout << A / (C - B) + 1;
	}
	
	return 0;
}
