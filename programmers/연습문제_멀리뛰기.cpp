//https://programmers.co.kr/learn/courses/30/lessons/12914


#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long x[2001] = { 0 };
long long solution(int n)
{
	long long answer = 0;
	x[0] = 1;
	x[1] = 1;
	x[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		x[i] = (x[i - 1] + x[i - 2]) % 1234567;

	}
	answer = x[n];
	return answer;
}

int main(void)
{
	int n1 = 4, n2 = 3;
	cout << solution(n2);
	return 0;
}