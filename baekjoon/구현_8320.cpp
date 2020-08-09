//https://www.acmicpc.net/problem/8320


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	
	long long cnt = 0;
	
		cnt = 0;
		cin >> N;
		
		for (int i = 1; i <= (N+1)/2; i++)
		{
			for (int j = i; j <= N; j++)
			{
				if (i * j <= N)
				{
					cnt++;
				}
			}
		}
		cout << cnt<<endl;
	
	return 0;
}