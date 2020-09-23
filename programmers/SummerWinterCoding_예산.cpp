//https://programmers.co.kr/learn/courses/30/lessons/12982


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
	long long sum = 0;
	int answer = 0;
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++)
	{
		sum += d[i];
		if (sum <= budget)
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	return answer;
}

int main(void)
{
	vector<int> d1 = { 1,3,2,5,4 }, d2 = { 2,2,3,3 };
	int budget1 = 9, budget2 = 10;
	cout << solution(d2, budget2);
	return 0;
}