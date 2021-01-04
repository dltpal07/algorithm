//https://programmers.co.kr/learn/courses/30/lessons/12924


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;
	answer += 1;
	if (n % 2 == 1)
		answer++;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0 && ((n / i) % 2 == 1))
		{
			
			answer++;
		}
	}
	return answer;
}

int main(void)
{
	int n = 12;
	cout << solution(n);
	return 0;
}