//https://programmers.co.kr/learn/courses/30/lessons/12932


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
	vector<int> answer;
	while (n>0)
	{
		int x = n % 10;
		n = n / 10;
		answer.push_back(x);
	}
	return answer;
}

int main(void)
{
	long long n = 12345;
	vector<int> answer = solution(n);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}