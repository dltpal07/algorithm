//https://programmers.co.kr/learn/courses/30/lessons/68935


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
	int answer = 0;
	long long e = 1;
	string str = "";
	while (n > 0)
	{
		str += (char)((n % 3)+'0');
		n /= 3;
	}
	for (int i = str.size() - 1; i >= 0; i--)
	{
		answer += (str[i] - '0') * e;
		e *= 3;
	}
	return answer;
}

int main(void)
{
	int n1 = 45, n2 = 125, n3 = 100000000;
	cout<<solution(n2);
	return 0;
}