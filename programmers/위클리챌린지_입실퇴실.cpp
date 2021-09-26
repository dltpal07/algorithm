//https://programmers.co.kr/learn/courses/30/lessons/86048


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
	vector<int> answer;
	vector<int> in_room;
	vector<set<int>> v(enter.size() + 1);
	int i = 0;
	for (int j = 0; j < leave.size(); j++)
	{
		while(1)
		{
			if (find(in_room.begin(), in_room.end(), leave[j]) != in_room.end())
			{
				int dist = find(in_room.begin(), in_room.end(), leave[j]) - in_room.begin();
				in_room.erase(in_room.begin() + dist);
				break;
			}
			else
			{
				if (i < enter.size())
				{
					for (auto k:in_room)
					{
						v[k].insert(enter[i]);
						v[enter[i]].insert(k);
					}
					in_room.push_back(enter[i]);
					
				}
				i++;
			}

		}
	}
	for (int i = 1; i <= enter.size(); i++)
	{
		answer.push_back(v[i].size());
	}
	return answer;
}

int main(void)
{
	vector<int> enter1 = { 1, 3, 2 }, enter2 = { 1, 4, 2, 3 },
		enter3 = { 3, 2, 1 }, enter4 = { 3, 2, 1 }, enter5 = { 1, 4, 2, 3 };
	vector<int> leave1 = { 1, 2, 3 }, leave2 = { 2, 1, 3, 4 }, leave3 = { 2, 1, 3 },
		leave4 = { 1, 3, 2 }, leave5 = { 2, 1, 4, 3 };
	vector<int> answer = solution(enter5, leave5);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}