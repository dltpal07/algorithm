//https://programmers.co.kr/learn/courses/30/lessons/68936


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> m;

void DFS(int x, int y, int size, vector<int> &answer)
{
	bool zero = true, one = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (m[i][j] == 1)
				zero = false;
			if (m[i][j] == 0)
				one = false;
		}
	}
	if (zero == true)
	{
		answer[0]++;
		return;
	}
	if (one == true)
	{
		answer[1]++;
		return;
	}
	DFS(x, y, size / 2, answer);
	DFS(x, y + size / 2, size / 2, answer);
	DFS(x + size / 2, y, size / 2, answer);
	DFS(x + size / 2, y + size / 2, size / 2, answer);
}

vector<int> solution(vector<vector<int>> arr)
{
	vector<int> answer(2, 0);
	m = arr;
	DFS(0, 0, arr.size(), answer);
	return answer;
}

int main(void)
{
	vector<vector<int>> arr1 = {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}};
	vector<vector<int>> arr2 = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 1, 1}};
	vector<int> answer = solution(arr2);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}