//https://programmers.co.kr/learn/courses/30/lessons/12909


#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	queue<char> q;
	for (int i = 0; i < s.size(); i++)
	{
		if (q.empty())
			q.push(s[i]);
		else
		{
			if (q.front() == '(')
			{
				if (s[i] == ')')
					q.pop();
				else
					q.push(s[i]);
			}
		}
	}
	if (q.empty())
		answer = true;
	else
		answer = false;
	return answer;
}

int main(void)
{
	string s1 = "()()", s2 = "(())()", s3 = ")()(", s4 = "(()(";
	cout << solution(s4);
	return 0;
}