//https://programmers.co.kr/learn/courses/30/lessons/42748


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands)
{
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++)
	{
		vector<int> tmp;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			tmp.push_back(arr[j]);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[commands[i][2] - 1]);
	}
	return answer;
}

int main(void)
{

	vector<int> arr = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };
	vector<int> answer = solution(arr, commands);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}