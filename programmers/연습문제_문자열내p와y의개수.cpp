//https://programmers.co.kr/learn/courses/30/lessons/12916


#include <iostream>
#include <string>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int p_cnt = 0, y_cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			p_cnt++;
		if (s[i] == 'y' || s[i] == 'Y')
			y_cnt++;
	}
	if (p_cnt == y_cnt)
		answer = true;
	else
		answer = false;

	return answer;
}

int main(void)
{
	string s1 = "pPoooyY", s2 = "Pyy";
	cout << solution(s2);
	return 0;
}