//https://programmers.co.kr/learn/courses/30/lessons/12926


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = "";
	char ch;
	int tmp = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			answer += s[i];
		else
		{
			if (s[i] >= 'A' &&s[i] <= 'Z')
			{
				tmp = int(s[i]) + n;
				if (tmp > 'Z')
					tmp -= 'Z' - 'A' + 1;
				answer += char(tmp);
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				tmp = s[i] + n;
				if (tmp > 'z')
				{
					tmp -= 'z' - 'a' + 1;
				}
				answer += char(tmp);
			}
		}
	}
	return answer;
}

int main(void)
{
	string s1 = "Z", s2 = "z", s3 = "a B z";
	int n1 = 1, n2 = 1, n3 = 25;
	cout << solution(s3, n3);
	return 0;
}