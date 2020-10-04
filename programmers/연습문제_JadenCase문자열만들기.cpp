//https://programmers.co.kr/learn/courses/30/lessons/12951


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";
	bool flag = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (!flag)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
			{
				s[i] -= 32;
			}
			flag = true;
		}
		else
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
		if (s[i] == ' ')
			flag = false;
	}
	answer = s;
	return answer;
}

int main(void)
{
	string s1 = "3people unFollowed me", s2 = "for the last week";
	cout << solution(s2);
	return 0;
}