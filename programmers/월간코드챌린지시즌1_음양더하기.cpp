//https://programmers.co.kr/learn/courses/30/lessons/76501


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
	int answer = 0;
	for (int i = 0; i < absolutes.size(); i++)
	{
		if (signs[i] == false)
		{
			answer -= absolutes[i];
		}
		else
		{
			answer += absolutes[i];
		}
	}
	return answer;
}

int main(void)
{
	vector<int> absolutes1 = { 4, 7, 12 }, absolutes2 = { 1, 2, 3 };
	vector<bool> signs1 = { true,false,true }, signs2 = { false,false,true };
	cout << solution(absolutes2, signs2);
	return 0;
}