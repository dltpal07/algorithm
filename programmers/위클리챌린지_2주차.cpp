//https://programmers.co.kr/learn/courses/30/lessons/83201?language=cpp


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string grade(int score)
{
	if (score >= 90)
	{
		return "A";
	}
	else if (score >= 80)
	{
		return "B";
	}
	else if (score >= 70)
	{
		return "C";
	}
	else if (score >= 50)
	{
		return "D";
	}
	else
	{
		return "F";
	}
}

string solution(vector<vector<int>> scores)
{
	string answer = "";
	int min, max, total, min_cnt, max_cnt, total_num;
	vector<vector<int>> new_scores(scores.size(), vector<int> (scores.size()));
	for (int i = 0; i < scores.size(); i++)
	{
		for (int j = 0; j < scores[i].size(); j++)
		{
			new_scores[i][j] = scores[j][i];
		}
	}
	scores = new_scores;
	for (int i = 0; i < scores.size(); i++)
	{
		min = *min_element(scores[i].begin(), scores[i].end());
		min_cnt = count(scores[i].begin(), scores[i].end(), min);
		max = *max_element(scores[i].begin(), scores[i].end());
		max_cnt = count(scores[i].begin(), scores[i].end(), max);
		total = accumulate(scores[i].begin(), scores[i].end(), 0);
		total_num = scores[i].size();
		if ((scores[i][i] == min && min_cnt == 1) || (scores[i][i] == max && max_cnt == 1))
		{
			total -= scores[i][i];
			total_num -= 1;
		}
		total = (float)total / total_num;
		answer += grade(total);
	}
	return answer;
}

int main(void)
{
	vector<vector<int>> scores1 = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}},
		scores2 = {{50, 90}, {50, 87}}, scores3 = {{70, 49, 90}, {68, 50, 38}, {73, 31, 100}};
	string result = solution(scores3);

	return 0;
}