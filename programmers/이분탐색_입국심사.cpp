//https://programmers.co.kr/learn/courses/30/lessons/43238


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

unsigned long long solution(int n, vector<int> times)
{
	unsigned long long answer = 0;
	sort(times.begin(), times.end());
	unsigned long long low = 1;
	unsigned long long high = times[times.size() - 1] * n;
	while (low <= high)
	{
		unsigned long long mid = (low + high) / 2;
		unsigned long long cnt = 0;
		for (int i = 0; i < times.size(); i++)
		{
			cnt += mid / times[i];
		}
		if (cnt >= n)
		{
			if (answer == 0)
				answer = mid;
			else
				answer = min(answer, mid);
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return answer;
}

int main(void)
{
	int n = 6;
	vector<int> times = { 7, 10 };
	cout << solution(n, times);
	return 0;
}