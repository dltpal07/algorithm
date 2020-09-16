//https://programmers.co.kr/learn/courses/30/lessons/12935


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	int min = 987654321;
	int idx = 0;
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			idx = i;
		}
	}
	arr.erase(arr.begin() + idx, arr.begin() + idx + 1);
	if (arr.empty())
		arr.push_back(-1);
	answer = arr;
	return answer;
}

int main(void)
{
	vector<int> arr1 = { 4,3,2,1 }, arr2 = { 10 };
	vector<int> answer = solution(arr2);
	for (auto x : answer)
	{
		cout << x;
	}
	return 0;
}