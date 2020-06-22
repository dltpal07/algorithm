//https://www.acmicpc.net/problem/11049


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 500;
const int INF = 987654321;

int N;
pair<int, int> matrix[MAX];
int cache[MAX][MAX];

int minCalc(int left, int right)
{
	if (left == right)
	{
		return 0;
	}
	int &result = cache[left][right];
	if (result != -1)
		return result;
	result = INF;
	for (int i = left; i < right; i++)
	{
		result = min(result, minCalc(left, i) + minCalc(i + 1, right)
			+ matrix[left].first*matrix[i].second*matrix[right].second);
	}
	return result;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> matrix[i].first >> matrix[i].second;
	}
	memset(cache, -1, sizeof(cache));
	cout << minCalc(0, N - 1) << endl;
	return 0;
}