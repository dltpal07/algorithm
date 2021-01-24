//https://programmers.co.kr/learn/courses/30/lessons/12946


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v;

void hanoi(int n, int from, int tmp, int to)
{
	if (n == 1)
	{
		vector<int> tv;
		tv.push_back(from);
		tv.push_back(to);
		v.push_back(tv);
	}
	else
	{
		vector<int> tv;
		hanoi(n - 1, from, to, tmp);
		tv.push_back(from);
		tv.push_back(to);
		v.push_back(tv);
		hanoi(n - 1, tmp, from, to);
	}
}

vector<vector<int>> soiution(int n)
{
	vector<vector<int>> answer;
	hanoi(n, 1, 2, 3);
	answer = v;
	return answer;
}



int main(void)
{
	int n = 2;
	vector<vector<int>> answer = soiution(n);
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