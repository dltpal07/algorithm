//https://programmers.co.kr/learn/courses/30/lessons/12949


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;
	int idx_i, idx_j;
	for (int i = 0; i < arr1.size(); i++)
	{
		vector<int> arr3;
		for (int j = 0; j < arr2[0].size(); j++)
		{
			int tmp = 0;
			idx_j = 0;
			while (idx_j < arr2.size())
			{
				tmp += arr1[i][idx_j] * arr2[idx_j][j];
				idx_j++;
			}
			arr3.push_back(tmp);
		}
		answer.push_back(arr3);

	}

	return answer;
}

int main(void)
{
	vector<vector<int>> arr11 = { {1,4},{3,2},{4,1} }, arr12 = { {3,3},{3,3} };
	vector<vector<int>> arr21 = { {2,3,2},{4,2,4,},{3,1,4} }, arr22 = { {5,4,3},{2,4,1},{3,1,1} };
	vector<vector<int>> arr31 = { {1,2},{3,4} }, arr32 = { {5,6,7},{8,9,10} };
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