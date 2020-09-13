//https://programmers.co.kr/learn/courses/30/lessons/12918


#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	if (!(s.size() == 4 || s.size() == 6))
		answer = false;
	if (answer)
	{
		for (int i = 0; i < s.size(); i++)
		{

			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				answer = false;
			}
		}
	}
	
	return answer;
}

int main(void)
{
	string s1 = "a234", s2 = "1234";
	cout << solution(s1);
	return 0;
}