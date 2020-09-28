//https://programmers.co.kr/learn/courses/30/lessons/42842


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;
	vector<pair<int, int>> v;
	for (int i = 1; i <= (yellow + 1 / 2); i++)
	{
		if (yellow%i == 0)
		{
			v.push_back({ i,yellow/i });
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if ((v[i].first + 2)*(v[i].second + 2) == brown + yellow)
		{
			answer.push_back(v[i].second+2);
			answer.push_back(v[i].first+2);
			break;
		}
	}
	return answer;
}