//https://programmers.co.kr/learn/courses/30/lessons/12933


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n)
{
	long long e = 1;
	vector<int> v;
	long long answer = 0;
	while (n > 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		answer += e * v[i];
		e *= 10;
	}
	return answer;
}

int main(void)
{
	long long n = 118372;
	cout << solution(n);
	return 0;
}