//https://programmers.co.kr/learn/courses/30/lessons/77484


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	int correct_num = 0, cnt = 0, max_val, min_val;
	cnt = count(lottos.begin(), lottos.end(), 0);

	for (int i = 0; i < win_nums.size(); i++)
	{
		if (count(lottos.begin(), lottos.end(), win_nums[i]) >0)
		{
			correct_num++;
		}
	}
	min_val = correct_num;
	max_val = correct_num + cnt;
	min_val = 7 - min_val;
	max_val = 7 - max_val;
	if (min_val >= 6)
		min_val = 6;
	if (max_val >= 6)
		max_val = 6;
	answer.push_back(max_val);
	answer.push_back(min_val);
	return answer;
}

int main(void)
{
	vector<int> lottos1 = { 44, 1, 0, 0, 31, 25 }, win_nums1 = { 31, 10, 45, 1, 6, 19 },
		lottos2 = { 0, 0, 0, 0, 0, 0 }, win_nums2 = { 38, 19, 20, 40, 15, 25 },
		lottos3 = { 45, 4, 35, 20, 3, 9 }, win_nums3 = { 20, 9, 3, 45, 4, 35 };
	vector<int> answer = solution(lottos3, win_nums3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}