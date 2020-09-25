//https://programmers.co.kr/learn/courses/30/lessons/49993


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < skill_trees.size(); i++)
	{
		int cur = 0;
		flag = true;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			if (skill.find(skill_trees[i][j]) != string::npos)
			{
				if (skill[cur] == skill_trees[i][j])
				{
					cur++;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
			answer++;
	}
	return answer;
}

int main(void)
{
	string skill = "CBD";
	vector<string> skill_trees = { "BACDE","CBADF","AECB","BDA" };
	cout << solution(skill, skill_trees);
	return 0;
}