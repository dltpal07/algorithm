//https://programmers.co.kr/learn/courses/30/lessons/42862


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<int> v(n, 1);
	for (int i = 0; i < lost.size(); i++)
	{
		v[lost[i] - 1]--;
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		v[reserve[i] - 1]++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > 1)
		{
			if (i - 1 >= 0 && v[i - 1] == 0)
			{
				v[i - 1]++;
				v[i]--;
			}
			else if (i + 1 < n && v[i + 1] == 0)
			{
				v[i + 1]++;
				v[i]--;
			}
		}
	}
	answer = count(v.begin(), v.end(), 0);
	answer = n - answer;
	return answer;
}

int main(void)
{
	int n1 = 5, n2 = 5, n3 = 3;
	vector<int> lost1 = { 2,4 }, lost2 = { 2,4 }, lost3 = { 3 };
	vector<int> reserve1 = { 1,3,5 }, reserve2 = { 3 }, reserve3 = { 1 };
	cout << solution(n3, lost3, reserve3);
	return 0;
}