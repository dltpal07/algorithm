//https://programmers.co.kr/learn/courses/30/lessons/12906


#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	answer.push_back(arr[0]);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != arr[i - 1])
		{
			answer.push_back(arr[i]);
		}
	}
	return answer;
}

int main(void)
{
	vector<int> arr1 = { 1,1,3,3,0,1,1 }, arr2 = { 4,4,4,3,3 };
	vector<int> answer;
	answer = solution(arr2);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}