// https://programmers.co.kr/learn/courses/30/lessons/92342

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int, vector<int>>> answer_vec;

bool compare(pair<int, vector<int>>p1, pair<int, vector<int>> p2)
{
	if (p1.first == p2.first)
	{

		return p1.second > p2.second;
	}
	return p1.first > p2.first;

}

void DFS(vector<int> info, vector<int> b_vec, int cnt, int n, int cur_j)
{
	if (cnt == n)
	{
		int a_score = 0, b_score = 0;
		
		for (int i = 0; i < 10; i++)
		{
			if (info[i] > 0 && info[i] >= b_vec[i])
			{
				a_score += (10 - i);
			}
			else if (b_vec[i] > 0)
			{
				b_score += (10 - i);
			}
		}
		if (b_score > a_score)
		{
			reverse(b_vec.begin(), b_vec.end());
			answer_vec.push_back({ b_score - a_score, b_vec });
		}
		return;
	}
	for (int j = cur_j; j <= 10; j++)
	{
		b_vec[j]++;
		cnt++;
		DFS(info, b_vec, cnt, n, j);
		cnt--;
		b_vec[j]--;
	}
	
}

vector<int> solution(int n, vector<int> info)
{
	vector<int> b_vec(11, 0);
	vector<int> answer;
	DFS(info, b_vec, 0, n, 0);
	if (answer_vec.size() == 0)
		answer.push_back(-1);
	else
	{
		sort(answer_vec.begin(), answer_vec.end(), compare);
		answer = answer_vec[0].second;
		reverse(answer.begin(), answer.end());
	}
	
	return answer;
}

int main(void)
{
	int n1 = 5, n2 = 1, n3 = 9, n4 = 10;
	vector<int> info1 = { 2,1,1,1,0,0,0,0,0,0,0 }, info2 = { 1,0,0,0,0,0,0,0,0,0,0 }, info3 = { 0,0,1,2,0,1,1,1,1,1,1 }, info4 = { 0,0,0,0,0,0,0,0,3,4,3 };
	vector<int> result = solution(n4, info4);

	for (auto x : result)
	{
		cout << x << " ";
	}
	return 0;
}