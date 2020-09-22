//https://programmers.co.kr/learn/courses/30/lessons/12950


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;
	for (int i = 0; i < arr1.size(); i++)
	{
		vector<int> tmp;
		for (int j = 0; j < arr1[i].size(); j++)
		{
			tmp.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(tmp);
	}
	return answer;
}

int main(void)
{
	vector<vector<int>> arr11 = { {1,2}, {2,3} }, arr12 = { {3,4}, {5,6} }, arr21 = { {1},{2} }, arr22 = { {3},{4} };
	vector<vector<int>> answer = solution(arr21, arr22);
	for (auto x : answer)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}