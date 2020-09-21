//https://programmers.co.kr/learn/courses/30/lessons/12944


#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
	double answer = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		answer += arr[i];
	}
	answer /= (double)(arr.size());
	return answer;
}

int main(void)
{
	vector<int> arr1 = { 1,2,3,4 }, arr2 = { 5,5 };
	cout << solution(arr2);
	return 0;
}