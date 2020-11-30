//https://programmers.co.kr/learn/courses/30/lessons/17684


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg)
{
	vector<int> answer;
	map<string, int> m;
	bool flag = false;
	for (int i = 0; i < 26; i++)
	{
		char tmp = 'A' + i;
		string t = "";
		t += tmp;
		m[t] = i;
	}
	for (int i = 0; i < msg.size(); i++)
	{
		string tmp = "";
		int output, idx;
		flag = false;
		for (int j = i; j < msg.size(); j++)
		{
			tmp += msg[j];
			if (m.find(tmp) == m.end())
			{
				i+=tmp.size()-2;
				flag = true;
				
				break;
			}
			else
			{
				output = m[tmp];
				idx = j;
			}

		}
		answer.push_back(output + 1);
		if (idx == msg.size() - 1)
			break;

		if(flag)
			m[tmp] = m.size();

	}
	return answer;
}

int main(void)
{
	vector<int> answer = solution("ABABABABABABABAB");
	for (auto x : answer)
	{
		cout << x << ", ";
	}
	return 0;
}