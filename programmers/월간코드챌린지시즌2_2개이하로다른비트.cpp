//https://programmers.co.kr/learn/courses/30/lessons/77885


#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 2 == 0)
			answer.push_back(numbers[i] + 1);
		else
		{
			long long bit = 1;
			while (1)
			{
				if ((numbers[i] & bit) == 0)
					break;
				bit <<= 1;
			}
			bit /= 2;
			answer.push_back(numbers[i] + bit);
		}
	}
	
	return answer;
}

int main(void)
{
	vector<long long> numbers = { 2, 7 };
	vector<long long> answer = solution(numbers);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	
	return 0;
}