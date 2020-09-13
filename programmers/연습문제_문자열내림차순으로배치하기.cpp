//https://programmers.co.kr/learn/courses/30/lessons/12917


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
	string answer = "";
	vector<char> c;
	for (int i = 0; i < s.size(); i++)
	{
		c.push_back(s[i]);
	}
	sort(c.begin(), c.end(), greater<int>());
	for (int i = 0; i < c.size(); i++)
	{
		answer += c[i];
	}
	return answer;
}

int main(void)
{
	string s = "Zbcdefg";
	string answer = solution(s);
	cout << answer;
	return 0;
}