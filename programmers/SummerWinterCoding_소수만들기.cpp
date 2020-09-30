//https://programmers.co.kr/learn/courses/30/lessons/12977


#include <iostream>
#include <vector>
using namespace std;

int prime[3001] = { 0 };
int checked[1001] = { 0 };
int sum = 0;
vector<int> sums;
void DFS(int cnt, vector<int> nums, int cur_i)
{
	if (cnt == 3)
	{
		sums.push_back(sum);
		return;
	}
	for (int i = cur_i; i < nums.size(); i++)
	{
		if (checked[i] == 0)
		{
			sum += nums[i];
			checked[i] = 1;
			DFS(++cnt, nums, i + 1);
			checked[i] = 0;
			sum -= nums[i];
			cnt--;
		}

	}
}


int solution(vector<int> nums)
{
	int answer = 0;
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i*i <= 3000; i++)
	{
		for (int j = 2; i*j <= 3000; j++)
		{
			prime[i*j] = 1;
		}
	}
	DFS(0, nums, 0);
	for (auto x : sums)
	{
		if (prime[x] == 0)
			answer++;
	}
	return answer;
}

int main(void)
{
	vector<int> nums1 = { 1,2,3,4 }, nums2 = { 1,2,7,6,4 };
	cout << solution(nums2);
	return 0;
}
