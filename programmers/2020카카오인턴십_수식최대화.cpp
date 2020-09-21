//https://programmers.co.kr/learn/courses/30/lessons/67257


#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool checked[3];
vector<vector<int>> v;
vector<int> tmp;
vector<char> oper_vec;

void factorial(int cnt)
{
	if (cnt == oper_vec.size())
	{
		v.push_back(tmp);
	}
	for (int i = 0; i < oper_vec.size(); i++)
	{
		if (checked[i] == false)
		{
			checked[i] = true;
			tmp.push_back(i);
			factorial(cnt + 1);
			tmp.pop_back();
			checked[i] = false;
		}
	}
}

long long solution(string expression) {
	long long answer = 0;
	string str;
	vector<long long> init_num;
	vector<char> init_oper;
	vector<long long> num; // 숫자
	vector<char> oper; // 연산자
	set<char> oper_set;
	long long _max = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			init_oper.push_back(expression[i]);
			if (str.size() != 0)
			{
				init_num.push_back(stoi(str));
				str = "";

			}
		}
		else
		{
			str += expression[i];
		}
	}
	init_num.push_back(stoi(str));
	for (auto s : init_oper)
	{
		oper_set.insert(s);
	}
	int it = 0;
	for (auto s : oper_set)
	{
		oper_vec.push_back(s);
		
	}
	factorial(0);
	
	for (int i = 0; i < v.size(); i++)
	{
		num = init_num;
		oper = init_oper;
		for (int j = 0; j < v[i].size(); j++)
		{
			while (1)
			{
				if (find(oper.begin(), oper.end(), oper_vec[v[i][j]]) == oper.end())
				{
					break;
				}
				else
				{
					int index = find(oper.begin(), oper.end(), oper_vec[v[i][j]]) - oper.begin();
					if (oper_vec[v[i][j]] == '+')
					{
						num[index] = num[index] + num[index + 1];
						num.erase(num.begin() + index + 1);
						oper.erase(oper.begin() + index);
					}
					else if (oper_vec[v[i][j]] == '-')
					{
						num[index] = num[index] - num[index + 1];
						num.erase(num.begin() + index + 1);
						oper.erase(oper.begin() + index);
					}
					else if (oper_vec[v[i][j]] == '*')
					{
						num[index] = num[index] * num[index + 1];
						num.erase(num.begin() + index + 1);
						oper.erase(oper.begin() + index);
					}
					
				}
			}
		}
		if (_max < abs(num[0]))
		{
			_max = abs(num[0]);
		}
	}
	
	return _max;
}

int main(void)
{
	string expression = "50*6-3*2";
	
	cout<<solution(expression);
	return 0;
}