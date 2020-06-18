//https://www.acmicpc.net/problem/1003


#include <iostream>
using namespace std;
#include <ctime>

int main(void)
{
	int fibo[41],n,tmp;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 0; i < 39; i++)
	{
		fibo[i + 2] = fibo[i] + fibo[i + 1];
	}
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> tmp;
		if (tmp == 0)
		{
			cout << 1 << " " << 0 << "\n";
		}
		else
		{
			cout << fibo[tmp - 1] << " " << fibo[tmp - 0] << "\n";
		}
	}
	return 0;
}