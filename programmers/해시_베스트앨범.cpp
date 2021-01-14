//https://programmers.co.kr/learn/courses/30/lessons/42579


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	map<int, string, greater<int>> m1;
	map<string, int> m2;
	for (int i = 0; i < genres.size(); i++)
	{
		m2[genres[i]] += plays[i];
	}
	map<string, int>::iterator iter;
	for (iter = m2.begin(); iter != m2.end(); iter++)
	{
		m1[iter->second] = iter->first;
	}
	map < string, vector<pair<int, int>>> m3;
	for (int i = 0; i < plays.size(); i++)
	{
		m3[genres[i]].push_back({ plays[i], -1 * i });
	}
	map < string, vector<pair<int, int>>>::iterator iter2;
	for (iter2 = m3.begin(); iter2 != m3.end(); iter2++)
	{
		sort(iter2->second.begin(), iter2->second.end(), greater<>());
	}
	map<int, string>::iterator iter3;
	for (iter3 = m1.begin(); iter3 != m1.end(); iter3++)
	{
		for (int i = 0; i < m3[iter3->second].size() && i<2; i++)
		{
			answer.push_back(-1 * m3[iter3->second][i].second);
			//cout << m3[iter3->second][i].first << " " << m3[iter3->second][i].second << endl;
		}
	}
	return answer;
}

int main(void)
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	vector<int> answer;
	answer = solution(genres, plays);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}