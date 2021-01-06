//https://programmers.co.kr/learn/courses/30/lessons/42860


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(string name)
{
	int answer = 0;
	int st = 0, ed = 0;
	vector<int> index;
	bool flag = false;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == 'A')
			continue;
		else
		{
			if (flag == false)
			{
				flag = true;
				st = i;
			}
			ed = i;
			index.push_back(i);
		}
		int front, back;
		front = name[i] - 'A';
		back = 'Z' - name[i] + 1;
		if (front < back)
			answer += front;
		else
			answer += back;
	}
	int c1, c2, c3, max_val = 0, max_idx1=0, max_idx2 = 0;
	c1 = ed;
	c2 = name.size() - st;
	for (int i = 0; i < index.size() - 1; i++)
	{
		if (max_val < index[i + 1] - index[i])
		{
			max_val = index[i + 1] - index[i];
			max_idx1 = index[i];
			max_idx2 = index[i + 1];
		}
	}
	c3 = max_idx1 * 2 + name.size() - max_idx2;
	answer += min(min(c1, c2), c3);
	return answer;
}

int main(void)
{
	string name1 = "JEROEN", name2 = "JAN";
	cout << solution(name2);
	return 0;
}