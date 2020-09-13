//https://programmers.co.kr/learn/courses/30/lessons/12925


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;
	answer = stoi(s);
	return answer;
}

int main(void)
{
	string s1 = "1234", s2 = "-1234";
	cout << solution(s2);
	return 0;
}