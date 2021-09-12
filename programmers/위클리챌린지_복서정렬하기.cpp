//https://programmers.co.kr/learn/courses/30/lessons/85002


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head)
{
	vector<int> answer;
	vector<pair<pair<pair<double, int>, int>, int>> win_count;
	vector<int> weight_count;
	map<int, vector<pair<int, int>>> m;
	
	for (int i = 0; i < head2head.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < head2head[i].size(); j++)
		{
			if (head2head[i][j] == 'W')
			{
				if (weights[i] < weights[j])
					cnt++;
			}
		}
		weight_count.push_back(cnt);
	}
	for (int i = 0; i < head2head.size(); i++)
	{
		double win_per = 0.0;
		double win = count(head2head[i].begin(), head2head[i].end(), 'W');
		double loose = count(head2head[i].begin(), head2head[i].end(), 'L');
		if (win == 0 && loose == 0)
			win_per = 0;
		else
			win_per = win / (win + loose);
		win_count.push_back({ { { win_per, weight_count[i] },  weights[i]}, -i});

	}
	sort(win_count.begin(), win_count.end(),  greater<>());
	for (auto x : win_count)
	{
		answer.push_back(-x.second + 1);
	}
		
	return answer;
}

int main(void)
{
	vector<int> weights1 = { 50,82,75,120 }, weights2 = { 145,92,86 },
		weights3 = { 60,70,60 };
	vector<string> head2head1 = { "NLWL","WNLL","LWNW","WWLN" },
		head2head2 = { "NLW","WNL","LWN" },
		head2head3 = { "NNN","NNN","NNN" };
	vector<int>answer = solution(weights3, head2head3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
		
	return 0;
}