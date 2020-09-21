//https://programmers.co.kr/learn/courses/30/lessons/67256


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int b_l = 10, b_r = 12, case_l, case_r;
	vector<int> left = { 1,4,7 }, right = { 3, 6, 9 };
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0)
			numbers[i] = 11;
		if (find(left.begin(), left.end(), numbers[i]) != left.end())
		{
			answer += 'L';
			b_l = numbers[i];
		}
		else if (find(right.begin(), right.end(), numbers[i]) != right.end())
		{
			answer += 'R';
			b_r = numbers[i];
		}
		else
		{
			case_l = abs(numbers[i] - b_l) / 3;
			case_l += abs(numbers[i] - b_l) % 3;
			case_r = abs(numbers[i] - b_r) / 3;
			case_r += abs(numbers[i] - b_r) % 3;
			if (case_l < case_r)
			{
				answer += 'L';
				b_l = numbers[i];
			}
			else if (case_r < case_l)
			{
				answer += 'R';
				b_r = numbers[i];
			}
			else
			{
				if (hand == "right")
				{
					answer += 'R';
					b_r = numbers[i];
				}
				else
				{
					answer += 'L';
					b_l = numbers[i];
				}
			}
		}
	}
	return answer;
}

int main(void)
{
	vector<int> numbers1 = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, numbers2 = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, numbers3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	string hand1 = "right", hand2 = "left", hand3 = "right";
	cout << solution(numbers2, hand2);
	return 0;
}