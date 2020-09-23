//https://programmers.co.kr/learn/courses/30/lessons/12954


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
	vector<long long> answer;
	long long tmp = x;
	for (int i = 0; i < n; i++)
	{
		answer.push_back(tmp);
		tmp += x;
	}
	return answer;
}

int main(void)
{
	int x1 = 2, n1 = 5, x2 = 4, n2 = 3, x3 = -4, n3 = 2;
	vector<long long> answer = solution(x3, n3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}