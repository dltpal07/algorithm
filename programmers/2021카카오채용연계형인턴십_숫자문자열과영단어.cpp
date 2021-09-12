//https://programmers.co.kr/learn/courses/30/lessons/81301


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s)
{
	map<string, int> m = { {"zero", 0}, {"one", 1}, {"two", 2},
	{"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9} };

	int answer = 0;
	int i = 0;
	for (auto x : m)
	{
		while (1)
		{
			int loc = s.find(x.first);
			if (loc >= s.size())
				break;
			s.replace(s.begin() + loc, s.begin() + loc + x.first.size(), to_string(x.second));
		}
	}
	answer = stoi(s);
	return answer;
}