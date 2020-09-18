//https://programmers.co.kr/learn/courses/30/lessons/12937


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num)
{
	string answer = "";
	if (num % 2 == 0)
	{
		answer = "Even";
	}
	else
	{
		answer = "Odd";
	}
	return answer;
}

int main(void)
{
	int num1 = 3, num2 = 4;
	cout << solution(num1);
	return 0;
}