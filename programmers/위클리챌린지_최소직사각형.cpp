//https://programmers.co.kr/learn/courses/30/lessons/86491


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes)
{
	int answer = 0, max1 = 0, max2 = 0;
	
	for (int i = 0;i<sizes.size();i++)
	{
		sort(sizes[i].begin(), sizes[i].end());
	}
	for (int i = 0; i < sizes.size(); i++)
	{
		max1 = max(max1, sizes[i][0]);
		max2 = max(max2, sizes[i][1]);
	}
	answer = max1 * max2;
	return answer;
}

int main(void)
{
	vector<vector<int>> sizes1 = {{60, 50}, {30, 70}, {60, 30}, {80, 40}},
		sizes2 = {{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}},
		sizes3 = {{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}};
	int answer = solution(sizes3);
	cout << answer;
	return 0;
}