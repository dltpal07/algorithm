//https://programmers.co.kr/learn/courses/30/lessons/12930


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			cnt = 0;
			continue;
		}
		if (cnt % 2 == 0)
		{
			if(s[i]>='a'&&s[i]<='z')
				s[i] = s[i] - 32;
			
		}
		else
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
				s[i] = s[i] + 32;
		}
		cnt++;
	}
	answer = s;
	return answer;
}

int main(void)
{
	string s = "try hello world";
	cout << solution(s);
	return 0;
}