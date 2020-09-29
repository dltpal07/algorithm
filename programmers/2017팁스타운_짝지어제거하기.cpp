//https://programmers.co.kr/learn/courses/30/lessons/12973


#include <iostream>
#include <string>
#include <queue>
using namespace std;

int solution(string s)
{
	int answer = 0;
	deque<char> A, B;
	A.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		B.push_front(s[i]);
	}
	while (!B.empty())
	{
		
		if (A.size() != 0 && A.back() == B.front())
		{
			A.pop_back();
			B.pop_front();
		}
		else
		{
			A.push_back(B.front());
			B.pop_front();
		}
	}
	if (A.size() == 0)
		return 1;
	else
		return 0;
}

int main(void)
{
	string s1 = "baabaa", s2 = "cdcd";
	cout << solution(s2);
	return 0;
}