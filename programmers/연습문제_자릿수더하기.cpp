//https://programmers.co.kr/learn/courses/30/lessons/12931


#include <iostream>

using namespace std;

int solution(int n)
{
	int answer = 0;
	while (n > 0)
	{
		answer += n % 10;
		n = n / 10;
	}
	
	return answer;
}

int main(void)
{
	
	int n1 = 123;
	cout << solution(n1);
	return 0;
}