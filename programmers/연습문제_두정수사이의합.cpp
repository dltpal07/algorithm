//https://programmers.co.kr/learn/courses/30/lessons/12912


#include <iostream>
#include <string>
#include <vector>


using namespace std;

long long solution(int a, int b)
{
	long long answer = 0;
	if (a < b)
	{
		for (int i = a; i <= b; i++)
		{
			answer += i;
		}
	}
	else
	{
		for (int i = b; i <= a; i++)
		{
			answer += i;
		}
	}
	return answer;
}

int main(void)
{
	int a1 = 3, b1 = 5, a2 = 3, b2 = 3, a3 = 5, b3 = 3;
	long long answer = solution(a3, b3);
	cout << answer;

	return 0;
}