//https://programmers.co.kr/learn/courses/30/lessons/12948


#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(string phone_number)
{
	string answer = "";
	int len = phone_number.size();
	len -= 4;
	for (int i = 0; i < len; i++)
	{
		answer += '*';
	}
	for (int i = len; i < len + 4; i++)
	{
		answer += phone_number[i];
	}
	return answer;
}

int main(void)
{
	string phone_number1 = "01033334444", phone_number2 = "027778888";
	cout << solution(phone_number2);
	return 0;
}