//https://programmers.co.kr/learn/courses/30/lessons/12928


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int sum = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
			sum += i;
	}
	return sum;
}

int main(void)
{
	int n1 = 12, n2 = 5;
	cout << solution(n1);
	return 0;
}