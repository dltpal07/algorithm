//https://programmers.co.kr/learn/courses/30/lessons/12985


#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;
	while (1)
	{
		if (a == b)
			break;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		answer++;
	}
	return answer;
}

int main(void)
{
	int N = 8, A = 4, B = 7;
	cout << solution(N, A, B);
	return 0;
}