//https://programmers.co.kr/learn/courses/30/lessons/12943


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
	long long n = num;
	bool flag = true;
	int cnt = 0;
	int answer = 0;
	while (1)
	{
		if (n == 1)
		{
			break;
		}
		else
		{
			if (cnt == 500)
				flag = false;
			if (n % 2 == 0)
			{
				n /= 2;
				cnt++;
			}
			else
			{
				n = n * 3 + 1;
				cnt++;
			}
			
		}
	}
	if (flag)
		return cnt;
	else
		return -1;
}

int main(void)
{
	int n1 = 6, n2 = 16, n3 = 626331;
	cout << solution(n3);
	return 0;
}