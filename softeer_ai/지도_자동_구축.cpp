//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=413


#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
	int n;
	
	cin >> n;
	long long answer[16];
	answer[0] = 2;
	for (int i = 1; i <= n; i++)
	{
		answer[i] = answer[i - 1] * 2 - 1;
	}
	cout << (answer[n] * answer[n]);
	return 0;
}