//https://programmers.co.kr/learn/courses/30/lessons/77884


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int left, int right)
{
	int answer = 0;
	for (int i = left; i <= right; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt % 2 == 0)
		{
			answer += i;
		}
		else
		{
			answer -= i;
		}
	}
	return answer;
}

int main(void)
{
	int left1 = 13, right1 = 17, left2 = 24, right2 = 27;
	cout << solution(left2, right2);
	return 0;
}