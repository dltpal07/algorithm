//https://programmers.co.kr/learn/courses/30/lessons/12921


#include <iostream>
#include <string>
#include <vector>

using namespace std;
int tmp[1000001] = { 0 };

int solution(int n)
{
	int answer = 0;
	for (int i = 2;i*i<=n; i++)
	{
		for (int j = i;j*i<=n; j++)
		{
			tmp[i*j]++;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (tmp[i] == 0)
			answer++;
	}
	return answer;
}

int main(void)
{
	int n1 = 10, n2 = 5;
	cout << solution(n2);
	return 0;
}