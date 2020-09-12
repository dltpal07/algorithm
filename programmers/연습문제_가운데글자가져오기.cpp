//https://programmers.co.kr/learn/courses/30/lessons/12903


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";
	int a = s.size();
	if (a % 2 == 0)
	{
		answer = s[a / 2 - 1];
		answer += s[a / 2];
	}
	else
		answer = s[a / 2];
	return answer;
}

int main(void)
{
	string s1 = "abcde", s2 = "qwer";
	cout << solution(s2);
	return 0;
}