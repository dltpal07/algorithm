//https://programmers.co.kr/learn/courses/30/lessons/12915


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
	vector<int> t;
	vector<string> answer;
	vector<pair<string, int>> answers;
	vector<char> tmp;
	for (int i = 0; i < strings.size(); i++)
	{
		answers.push_back({ strings[i][n] + strings[i], i });
	}
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
	{
		answer.push_back(strings[answers[i].second]);
	}
	return answer;
}

int main(void)
{
	vector<string> strings1 = { "sun", "bed", "car" }, strings2 = { "abce","abcd","cdx" };
	int n1 = 1, n2 = 2;
	vector<string> answer = solution(strings2, n2);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}