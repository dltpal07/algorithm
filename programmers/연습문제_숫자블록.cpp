// https://programmers.co.kr/learn/courses/30/lessons/12923

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> solution(long long begin, long long end)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> answer(end - begin + 1, 1);
	if (begin == 1)
	{
		answer[0] = 0;
	}
	for (long long i = begin; i <= end; i++)
	{
		for (long long j = 2; j <= sqrt(end); j++)
		{
			if (i % j == 0 && i / j <= 10000000)
			{
				answer[i - begin] = i / j;
				break;
			}
		}
	}
	return answer;
}

int main(void)
{
	long long begin = 1, end = 10;
	vector<int> answer = solution(begin, end);
	for (auto x : answer)
	{
		cout << x << endl;
	}
	return 0;
}