//https://programmers.co.kr/learn/courses/30/lessons/76502

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int check_correct(string str)
{
	stack<char> q;
	q.push(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (!q.empty())
		{
			if (q.top() == '(' && str[i] == ')')
				q.pop();
			else if (q.top() == '[' && str[i] == ']')
				q.pop();
			else if (q.top() == '{' && str[i] == '}')
				q.pop();

			else
				q.push(str[i]);
		}
		else
			q.push(str[i]);
	}
	if (q.size() == 0)
		return 1;
	else
		return 0;
}

int solution(string s)
{
	int answer = 0;
	for (int i = 0; i < s.size(); i++)
	{
		string cur_str = s.substr(i, s.size());
		cur_str += s.substr(0, i);
		answer += check_correct(cur_str);
	}
	return answer;
}

int main(void)
{
	string s1 = "[](){}", s2 = "}]()[{", s3 = "[)(]", s4 = "}}}";
	cout << solution(s4);
	return 0;
}