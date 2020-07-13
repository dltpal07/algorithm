//https://www.acmicpc.net/problem/2098


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 16;
const int INF = 987654321;

int N, W[MAX][MAX], cache[MAX][1 << MAX];

int TSP(int here, int visited)
{
	if (visited == (1 << N) - 1)
	{
		if (W[here][0] != 0)
			return W[here][0];
		else
			return INF;
	}
	int &result = cache[here][visited];
	if (result != -1)
	{
		return result;
	}
	result = INF;
	for (int next = 0; next < N; next++)
	{
		if (visited &(1 << next) || W[here][next] == 0)
			continue;
		int comp = W[here][next] + TSP(next, visited + (1 << next));
		result = min(result, comp);
	}
	return result;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	int result = INF;
	memset(cache, -1, sizeof(cache));
	cout << TSP(0, 1) << "\n";
	return 0;
}