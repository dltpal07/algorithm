//https://programmers.co.kr/learn/courses/30/lessons/1845


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int n = nums.size() / 2;
	int checked[200001] = { 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		checked[nums[i]] = 1;
	}
	int cnt = count(checked, checked + 200001, 1);
	if (cnt > n)
		answer = n;
	else
		answer = cnt;
	return answer;
}

int main(void)
{
	vector<int> nums1 = { 3, 1, 2, 3 }, nums2 = { 3, 3, 3, 2, 2, 4 }, nums3 = { 3, 3, 3, 2, 2, 2 };
	cout << solution(nums3);
	return 0;
}