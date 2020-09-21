//https://programmers.co.kr/learn/courses/30/lessons/12934


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
	long long answer = 0;
	answer = sqrt(n);
	if (answer * answer == n)
	{
		answer = pow((answer + 1), 2);
		return answer;
	}
	else
		return -1;
}

int main(void)
{
	int n1 = 121, n2 = 3;
	cout << solution(n2);
	return 0;
}