//https://programmers.co.kr/learn/courses/30/lessons/49994


#include <iostream>
#include <string>
#include <set>
using namespace std;


int solution(string dirs)
{
	int answer = 0, cur_j = 5, cur_i = 5;
	set<pair<pair<int, int>, pair<int, int>>> s;
	for (int i = 0; i < dirs.size(); i++)
	{
		if (dirs[i] == 'U')
		{
			if (cur_i <= 9)
			{
				s.insert({ {cur_i, cur_j}, {cur_i + 1, cur_j} });
				cur_i++;

			}
		}
		else if (dirs[i] == 'D')
		{
			if (cur_i >= 1)
			{
				s.insert({ {cur_i - 1, cur_j}, {cur_i, cur_j} });
				cur_i--;

			}
		}
		else if (dirs[i] == 'R')
		{
			if (cur_j <= 9)
			{
				s.insert({ {cur_i, cur_j}, {cur_i, cur_j + 1} });
				cur_j++;
				
			}
		}
		else if (dirs[i] == 'L')
		{
			if (cur_j >= 1)
			{

				s.insert({ {cur_i, cur_j - 1}, {cur_i, cur_j } });
				cur_j--;
				
			}
		}
	}
	answer = s.size();
	return answer;
}

int main(void)
{
	string str1 = "ULURRDLLU", str2 = "LULLLLLLU";
	cout << solution(str2);
	return 0;
}