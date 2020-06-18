//https://www.acmicpc.net/problem/2579


#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 301
#define endl "\n"

int N;
int arr[MAX];
int DP[MAX];
int Max(int A, int B)
{
	if (A > B)
		return A;
	return B;
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	DP[3] = Max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= N; i++)
	{
		DP[i] = Max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << DP[N];
	return 0;
}