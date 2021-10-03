//https://programmers.co.kr/learn/courses/30/lessons/86051


#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <numeric>
using namespace std;

int solution(vector<int> numbers)
{
	int answer = 45 - accumulate(numbers.begin(), numbers.end(), 0);

	return answer;
}

int main(void)
{
	vector<int> numbers1 = { 1,2,3,4,6,7,8,0 }, numbers2 = { 5,8,4,0,6,7,9 };
	cout << solution(numbers1);
	return 0;
}