//https://programmers.co.kr/learn/courses/30/lessons/12940


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

vector<int> solution(int n, int m)
{
	vector<int> answer;
	int gcd_ = gcd(n, m);
	int lcm_ = n * m / gcd_;
	answer.push_back(gcd_);
	answer.push_back(lcm_);
	return answer;
}

int main(void)
{
	int n1 = 3, n2 = 2, m1 = 12, m2 = 5;
	vector<int> answer = solution(n2, m2);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}