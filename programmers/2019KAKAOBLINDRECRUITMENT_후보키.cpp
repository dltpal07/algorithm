//https://programmers.co.kr/learn/courses/30/lessons/42890


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
vector<vector<int>> perm;
vector<int> tmp;
int cnt = 0;
int checked[8] = { 0 };
void make_permutation(vector<int> v, int num, int cur)
{
	if (cnt == num)
	{
		perm.push_back(tmp);
		return;
	}
	for (int i = cur; i < v.size(); i++)
	{
		if (checked[i] != 1)
		{
			checked[i] = 1;
			tmp.push_back(v[i]);
			cnt++;
			make_permutation(v, num, i + 1);
			cnt--;
			tmp.pop_back();
			checked[i] = 0;
		}
	}
}

int solution(vector<vector<string>> relation)
{
	int answer = 0;
	int t = 1;
	int origin_size = relation.size();
	vector<vector<string>> vvs;
	vector<int> v;
	vector<int> nums;
	for (int i = 0; i < relation[0].size(); i++)
	{
		v.push_back(i);
	}
	for (int i = 1; i <= v.size(); i++)
	{
		make_permutation(v, i, 0);
	}
	vector<bool> perm_bool(perm.size(), false);
	
	for (int i = 0; i < perm.size(); i++)
	{
		set<vector<string>> s;
		for (int k = 0; k < relation.size(); k++)
		{
			vector<string> vs;
			for (int j = 0; j < perm[i].size(); j++)
			{
				vs.push_back(relation[k][perm[i][j]]);
			}
			s.insert(vs);
			
		}
		
		nums.push_back(s.size());
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == origin_size)
		{
			perm_bool[i] = true;
		}
	}
	for (int i = 0; i < perm_bool.size(); i++)
	{
		if (perm_bool[i] == true)
		{
			for (int k = i + 1; k < perm.size(); k++)
			{
				int tmp_cnt = 0;

				for (int j = 0; j < perm[i].size(); j++)
				{
					if (find(perm[k].begin(), perm[k].end(), perm[i][j]) != perm[k].end())
					{
						tmp_cnt++;
					}
				}
				if (tmp_cnt == perm[i].size())
				{
					perm_bool[k] = false;
				}
			}
			
		}
	}
	answer = count(perm_bool.begin(), perm_bool.end(), true);
	return answer;
}