//https://programmers.co.kr/learn/courses/30/lessons/42584


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size(), 0);
	for (int i = 0; i < prices.size(); i++)
	{
		int j = i + 1;
		while (j<prices.size())
		{
			answer[i]++;
			if (prices[j] < prices[i])
				break;
			j++;
		}
	}
	return answer;
}

int main(void)
{
	vector<int> prices = { 1,2,3,2,3 };
	vector<int> answer = solution(prices);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}