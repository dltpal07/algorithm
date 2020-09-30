//https://programmers.co.kr/learn/courses/30/lessons/12911


#include <iostream>

using namespace std;

int solution(int n)
{
	int answer = 0;
	int tmp = 0;
	int t = n;
	int one_number = 0, compare_number = 0;
	while (t > 0)
	{
		if (t % 2 == 1)
		{
			one_number++;
		}
		t /= 2;
	}
	t = n + 1;
	while (1)
	{
		answer = t;
		compare_number = 0;
		while (t > 0)
		{
			if (t % 2 == 1)
			{
				compare_number++;
			}
			t /= 2;
		}
		if (compare_number == one_number)
			break;
		t = answer + 1;
	}
	return answer;
}

int main(void)
{
	int n1 = 78, n2 = 15;
	cout << solution(n2);
	return 0;
}