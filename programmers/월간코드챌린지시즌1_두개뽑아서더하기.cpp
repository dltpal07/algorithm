//https://programmers.co.kr/learn/courses/30/lessons/68644


#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;
	set<int> s;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			s.insert(numbers[i] + numbers[j]);
		}
	}
	for (auto x : s)
	{
		answer.push_back(x);
	}
	return answer;
}

int main(void)
{
	vector<int> numbers1 = { 2,1,3,4,1 }, numbers2 = { 5, 0, 2, 7 };
	vector<int> result = solution(numbers2);
	for (auto x : result)
	{
		cout << x << " ";
	}
	return 0;
}