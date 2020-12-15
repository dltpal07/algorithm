//https://programmers.co.kr/learn/courses/30/lessons/42839


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

vector<vector<int>> c;
vector<int> tmp;

bool checked[7];
void comb(int n, int max_, int cnt)
{
	if (cnt == n)
	{
		c.push_back(tmp);
		return;
	}
	for (int i = 0; i < max_; i++)
	{
		if (checked[i] == false)
		{
			tmp.push_back(i);
			checked[i] = true;
			comb(n, max_, cnt + 1);
			tmp.pop_back();
			checked[i] = false;
		}
	}
}

int solution(string numbers)
{
	int answer = 0;
	set<int> s;
	vector<int> v;
	for (int i = 1; i <= numbers.size(); i++)
	{
		memset(checked, false, sizeof(checked));
		comb(i, numbers.size(), 0);
	}
	for (int i = 0; i < c.size(); i++)
	{
		string str = "";
		for (int j = 0; j < c[i].size(); j++)
		{
			str += numbers[c[i][j]];
		}
		s.insert(stoi(str));
	}
	for (auto x : s)
	{
		v.push_back(x);
	}
	vector<int> primal(v[v.size() - 1] + 1, 0);
	primal[0] = 1;
	primal[1] = 1;

	for (int i = 2;i*i<=v[v.size() - 1];i++)
	{
		for (int j = 2;i*j<=v[v.size() - 1]; j++)
		{
			primal[i*j] = 1;
		}
	}
	for (auto x:v)
	{
		if (primal[x] == 0)
			answer++;
	}
	return answer;
}

int main(void)
{
	cout<<solution("17");
	return 0;
}