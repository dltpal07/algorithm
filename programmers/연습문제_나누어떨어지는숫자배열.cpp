//https://programmers.co.kr/learn/courses/30/lessons/12910


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % divisor == 0)
		{
			answer.push_back(arr[i]);
		}
	}
	if (answer.size() == 0)
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());
	return answer;
}

int main(void)
{
	vector<int> arr1 = { 5, 9, 7, 10 }, arr2 = { 2, 36, 1, 3 }, arr3 = { 3, 2, 6 };
	int divisor1 = 5, divisor2 = 1, divisor3 = 10;
	vector<int> answer = solution(arr3, divisor3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}