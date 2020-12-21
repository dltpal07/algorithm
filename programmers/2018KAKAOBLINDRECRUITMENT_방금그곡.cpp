//https://programmers.co.kr/learn/courses/30/lessons/17683


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos)
{
	string answer = "";
	vector<vector<string>> music;
	vector<int> time;
	vector<vector<string>> note;
	vector<vector<string>> play;
	vector<string> q_note;
	for (int i = 0; i < musicinfos.size(); i++)
	{
		vector<string> v;
		string str = "";
		for (int j = 0; j < musicinfos[i].size(); j++)
		{
			if (musicinfos[i][j] == ',')
			{
				v.push_back(str);
				str = "";
			}
			else
			{
				str += musicinfos[i][j];
			}
		}
		v.push_back(str);
		music.push_back(v);
	}
	for (int i = 0; i < music.size(); i++)
	{
		string a = "", b = "", c = "", d = "";
		a = music[i][0].substr(0, 2);
		b = music[i][0].substr(3, 2);
		c = music[i][1].substr(0, 2);
		d = music[i][1].substr(3, 2);
		int start = stoi(a) * 60 + stoi(b);
		int end = stoi(c) * 60 + stoi(d);
		time.push_back(end - start);
	}
	for (int i = 0; i < music.size(); i++)
	{
		vector<string> str;
		int idx = 0;
		while(idx < music[i][3].size())
		{
			string tmp = "";

			tmp += music[i][3][idx];
			idx++;
			if (music[i][3][idx] == '#')
			{
				tmp += music[i][3][idx];
				idx++;
			}
			str.push_back(tmp);
		}
		note.push_back(str);
	}
	int q_idx = 0;
	while (q_idx < m.size())
	{
		string tmp = "";

		tmp += m[q_idx];
		q_idx++;
		if (m[q_idx] == '#')
		{
			tmp += m[q_idx];
			q_idx++;
		}
		q_note.push_back(tmp);
	}
	for (int i = 0; i < time.size(); i++)
	{
		vector<string> v;
		int cnt = 0;
		while (cnt < time[i])
		{
			v.push_back(note[i][cnt%note[i].size()]);
			cnt++;
		}
		play.push_back(v);
	}
	int max_ = 0, answer_idx = 987654321;
	for (int i = 0; i < play.size(); i++)
	{
		for (int j = 0; j < play[i].size(); j++)
		{
			if (q_note[0] == play[i][j])
			{
				int idx = 0;
				int cnt = 0;
				while (idx < q_note.size() && j+idx<play[i].size())
				{
					if (q_note[idx] == play[i][j + idx])
					{
						cnt++;
					}
					else
					{
						break;
					}
					idx++;
				}
				if (cnt == q_note.size())
				{
					if (max_ < time[i])
					{
						max_ = time[i];
						answer_idx = i;
					}
				}
			}
		}
	}
	
	if (answer_idx == 987654321)
	{
		answer = "(None)";
	}
	else
	{
		answer = music[answer_idx][2];
	}
	return answer;
}

int main(void)
{
	string m1 = "ABCDEFG";
	vector<string> musicinfos1 = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEFG" };
	string m2 = "CC#BCC#BCC#BCC#B";
	vector<string> musicinfos2 = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };
	string m3 = "ABC";
	vector<string> musicinfos3 = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
	string answer = solution(m3, musicinfos3);

	cout << answer;
	return 0;
}