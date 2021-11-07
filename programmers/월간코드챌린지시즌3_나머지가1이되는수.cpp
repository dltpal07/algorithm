//https://programmers.co.kr/learn/courses/30/lessons/87389?language=cpp


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 2;
	n--;
	while (1)
	{
		if (n%answer == 0)
			break;
		answer++;
	}
	return answer;
}

int main(void)
{
	int n1 = 10, n2 = 12;
	cout << solution(n2);
	return 0;
}