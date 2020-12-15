//https://programmers.co.kr/learn/courses/30/lessons/68645


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int n)
{
	int result = 0;
	for (int i = n; i >= 1; i--)
	{
		result += i;
	}
	return result;
}

vector<int> solution(int n)
{
	int idx_i = 0, idx_j = 0;
	int idx_i2;
	int idx_j2;
	int max_ = factorial(n);
	vector<int> answer;
	vector<vector<int>> pyramid;
	vector<vector<bool>> checked;
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		vector<int> tmp(i);
		vector<bool> t(i, false);
		pyramid.push_back(tmp);
		checked.push_back(t);
	}
	while (num<=max_)
	{
		for (int i = idx_i; i < pyramid.size(); i++)
		{
			if (checked[i][idx_j] == false)
			{
				checked[i][idx_j] = true;
				pyramid[i][idx_j] = num;
				num++;
				idx_i2 = i;
			}
		}
		for (int j = 0; j < pyramid[idx_i2].size(); j++)
		{
			if (checked[idx_i2][j] == false)
			{
				checked[idx_i2][j] = true;
				pyramid[idx_i2][j] = num;
				num++;
				idx_j2 = j;
			}
		}
		for (int i = idx_i2 - 1; i >= 0; i--)
		{
			if (checked[i].size() <= idx_j2 - 1)
				break;
			if (checked[i][idx_j2 - 1] == false)
			{
				checked[i][idx_j2 - 1] = true;
				pyramid[i][idx_j2 - 1] = num;
				num++;
				idx_j2--;
				idx_i = i;
				idx_j = idx_j2-1;
			}
		}
		idx_i += 1;
		idx_j += 1;
		
	}
	for (auto x : pyramid)
	{
		for (auto y : x)
		{
			answer.push_back(y);
		}
	}
	return answer;
}

int main(void)
{
	solution(5);
	return 0;
}