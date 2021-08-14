//https://programmers.co.kr/learn/courses/30/lessons/77485


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	int cnt = 1;
	vector<int> answer;
	vector<vector<int>> matrix(rows, vector<int>(columns)), matrix2(rows, vector<int>(columns));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = cnt;
			cnt++;
		}
	}
	for (int q = 0; q < queries.size(); q++)
	{
		matrix2 = matrix;
		int start_i = queries[q][0] - 1, start_j = queries[q][1] - 1, end_i = queries[q][2] - 1, end_j = queries[q][3] - 1;
		int i, j, min = 987654321;
		i = start_i;
		j = start_j + 1;
		while (1)
		{
			if (min > matrix[i][j - 1])
				min = matrix[i][j - 1];
			matrix2[i][j] = matrix[i][j - 1];
			if (j == end_j)
				break;
			j++;
			
		}
		i++;
		while (1)
		{
			if (min > matrix[i - 1][j])
				min = matrix[i - 1][j];
			matrix2[i][j] = matrix[i - 1][j];
			if (i == end_i)
				break;
			i++;
		}
		j--;
		while (1)
		{
			if (min > matrix[i][j + 1])
				min = matrix[i][j + 1];
			matrix2[i][j] = matrix[i][j + 1];
			if (j == start_j)
				break;
			j--;
		}
		i--;
		while (1)
		{
			if (min > matrix[i + 1][j])
				min = matrix[i + 1][j];
			matrix2[i][j] = matrix[i + 1][j];
			if (i == start_i)
				break;
			i--;
		}
		answer.push_back(min);
		matrix = matrix2;
	}
	
	return answer;
}

int main(void)
{
	int rows1 = 6, columns1 = 6, rows2 = 3, columns2 = 3, rows3 = 100, columns3 = 97;
	vector<vector<int>> queries1 = {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}, queries2 = {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}, queries3 = {{1, 1, 100, 97}};
	vector<int> v = solution(rows3, columns3, queries3);
	for (auto x : v)
	{
		cout << x << " ";
	}
	return 0;
}