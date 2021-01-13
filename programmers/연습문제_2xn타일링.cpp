//https://programmers.co.kr/learn/courses/30/lessons/12900


#include <iostream>

using namespace std;

int x[60002];

int solution(int n)
{
	int answer = 0;
	x[0] = 0;
	x[1] = 1;
	for (int i = 2; i <= n+1; i++)
	{
		x[i] = (x[i - 1] + x[i - 2]) % 1000000007;
	}
	answer = x[n+1] % 1000000007;
	return answer;
}

int main(void)
{
	cout << solution(4);
	return 0;
}