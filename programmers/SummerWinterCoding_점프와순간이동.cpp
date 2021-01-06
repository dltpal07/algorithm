//https://programmers.co.kr/learn/courses/30/lessons/12980


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n)
{
	int answer = 0;
	while (1)
	{
		if (n < 2)
			break;
		answer++;
		int tmp = n;
		int cnt = 0;
		while (1)
		{
			if (tmp == 0)
				break;
			tmp/=2;
			cnt++;
		}
		n -= pow(2, cnt - 1);
	}
	answer += n;
	return answer;
}


int main(void)
{
	int n1 = 5, n2 = 6, n3 = 5000;
	cout << solution(n2);
	
	return 0;
}