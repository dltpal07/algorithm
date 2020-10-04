//https://programmers.co.kr/learn/courses/30/lessons/12939


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
	string answer = "";
	vector<string> v;
	vector<int> num;
	string tmp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			v.push_back(tmp);
			tmp = "";
		}
		else
			tmp += s[i];
	}
	v.push_back(tmp);
	for (int i = 0; i < v.size(); i++)
	{
		num.push_back(stoi(v[i]));
	}
	sort(num.begin(), num.end());
	answer += to_string(num[0]);
	answer += " ";
	answer += to_string(num[num.size() - 1]);
	return answer;
}

int main(void)
{
	string s1 = "1 2 3 4", s2 = "-1 -2 -3 -4", s3 = "-1 -1";
	cout << solution(s2);
	return 0;
}