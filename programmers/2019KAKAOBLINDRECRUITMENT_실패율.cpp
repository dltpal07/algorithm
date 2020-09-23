//https://programmers.co.kr/learn/courses/30/lessons/42889


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<double> player(N+2, 0);
	vector<pair<double, int>> failure(N+1);
	for (int i = 0; i < stages.size(); i++)
	{
		for (int j = 1; j <= stages[i]; j++)
		{
			player[j]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (player[i] == 0)
			failure[i] = { 0, i };
		else
			failure[i] = { (player[i] - player[i + 1])/player[i], i };
	}
	sort(failure.begin() + 1, failure.end(), compare);
	for (int i = 1; i < failure.size(); i++)
	{
		answer.push_back(failure[i].second);
	}
	return answer;
}

int main(void)
{
	vector<int> stages1 = { 2, 1, 2, 6, 2, 4, 3, 3 }, stages2 = { 4,4,4,4,4 };
	int N1 = 5, N2 = 4;
	vector<int> answer;
	answer = solution(N2, stages2);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}