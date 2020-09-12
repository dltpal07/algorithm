//https://programmers.co.kr/learn/courses/30/lessons/42840


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
	int max_val = 0;
	vector<int> answer;
	vector<int> cnt(3, 0);
	vector<int> c1 = { 1,2,3,4,5 }, c2 = { 2,1,2,3,2,4,2,5 }, c3 = { 3,3,1,1,2,2,4,4,5,5 };
	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == c1[i % 5])
			cnt[0]++;
		if (answers[i] == c2[i % 8])
			cnt[1]++;
		if (answers[i] == c3[i % 10])
			cnt[2]++;
	}
	for (int i = 0; i < 3; i++)
	{
		if (max_val < cnt[i])
			max_val = cnt[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (max_val == cnt[i])
			answer.push_back(i + 1);
	}
	return answer;
}

int main(void)
{
	vector<int> answers1 = { 1, 2, 3, 4, 5 }, answers2 = { 1,3,2,4,2 };
	vector<int> answer = solution(answers2);
	for (auto x : answer) {
		cout << x << " ";
	}
	return 0;
}