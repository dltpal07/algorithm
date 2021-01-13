//https://programmers.co.kr/learn/courses/30/lessons/43164


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool flag = false;
vector<pair<string, string>> road;
vector<vector<string>> tic;
vector<vector<pair<string, string>>> aa;
int visited[10001] = { 0 };
bool compare(vector<string> a, vector<string> b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	else
		return a[0] < b[0];
}

void DFS(int cnt)
{
	if (road.size() == tic.size())
	{
		flag = true;
		aa.push_back(road);
		return;
	}
	for (int i = 0; i < tic.size(); i++)
	{
		if (tic[i][0] == road[road.size() - 1].second && visited[i] == 0)
		{
			visited[i] = 1;
			road.push_back({tic[i][0], tic[i][1]});
			DFS(cnt+1);
			visited[i] = 0;
			road.pop_back();
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;
	sort(tickets.begin(), tickets.end(), compare);
	tic = tickets;
	
	for (int i = 0; i < tic.size(); i++)
	{
		if (flag)
			break;
		road.clear();
		memset(visited, 0, sizeof(visited));
		if (tic[i][0] == "ICN")
		{
			road.push_back({ tic[i][0], tic[i][1] });
			visited[i] = 1;
			DFS(1);
			visited[i] = 0;
			
		}

	}
	answer.push_back(aa[0][0].first);
	

	for (auto x : aa[0])
	{
		answer.push_back(x.second);
	}
	return answer;
}

int main(void)
{
	vector<vector<string>> tickets1 = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
	vector<vector<string>> tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
	vector<string> answer = solution(tickets1);
	for (auto x : answer)
	{
		cout << x << endl;
	}
	return 0;
}