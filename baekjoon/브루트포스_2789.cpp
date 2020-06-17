//https://www.acmicpc.net/problem/2798


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N, M,max = 0;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				if ((A[i] + A[j] + A[k] > max)&&(A[i]+A[j]+A[k]<=M))
				{
					max = A[i] + A[j] + A[k];
				}
			}
		}
	}
	cout << max;
	return 0;
}