//https://www.acmicpc.net/problem/10989


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int N,tmp, cnt1=0;
	cin >> N;
	int cnt[10001] = {0};
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		cnt[tmp]++;
	}
	
	
	for (int i = 1; i <= 10000; i++)
	{
		
			for (int j = 0; j < cnt[i]; j++)
			{
				cout << i << "\n";
			}
		
		
	}
	return 0;
}
