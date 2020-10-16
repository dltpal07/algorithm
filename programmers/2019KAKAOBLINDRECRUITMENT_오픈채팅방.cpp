//https://programmers.co.kr/learn/courses/30/lessons/42888


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record)
{
	vector<vector<string>> splited_record;
	vector<string> answer;
	vector<pair<string, string>> sub;
	map<string, string> m;
	for (int i = 0; i < record.size(); i++)
	{
		vector<string> tmp;
		string t;
		for (int j = 0; j < record[i].size(); j++)
		{
			if (record[i][j] != ' ')
			{
				t += record[i][j];
			}
			else
			{
				tmp.push_back(t);
				t = "";
			}
		}
		tmp.push_back(t);
		splited_record.push_back(tmp);
	}
	for (int i = 0; i < splited_record.size(); i++)
	{
		if (splited_record[i][0] == "Enter")
		{
			m[splited_record[i][1]] = splited_record[i][2];
			sub.push_back({ splited_record[i][1], "님이 들어왔습니다." });
		}
		else if (splited_record[i][0] == "Leave")
		{
			sub.push_back({ splited_record[i][1], "님이 나갔습니다." });
		}
		else if (splited_record[i][0] == "Change")
		{
			m[splited_record[i][1]] = splited_record[i][2];
		}
	}
	for (int i = 0; i < sub.size(); i++)
	{
		answer.push_back(m[sub[i].first] + sub[i].second);
	}
	return answer;
}

int main(void)
{
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> answer = solution(record);
	for (auto x : answer)
	{
		cout << x << endl;
	}
	return 0;
}