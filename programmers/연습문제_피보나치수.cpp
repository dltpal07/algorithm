//https://programmers.co.kr/learn/courses/30/lessons/12945


#include <iostream>
#include <string>
#include <vector>

using namespace std;
int fibo[100001];
int Fibo(int n)
{
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%1234567;
	}
	return fibo[n];
}

int solution(int n)
{
	int answer = 0;
	answer = Fibo(n);
	return answer;
}

int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		cout << solution(i)<<endl;
	}
	//cout << solution(5);
	return 0;
}