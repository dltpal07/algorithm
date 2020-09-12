//https://programmers.co.kr/learn/courses/30/lessons/12901?language=cpp


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int a, int b)
{
	string answer = "";
	vector<string> day = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	int sum = 0;
	int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < a - 1; i++)
		sum += month[i];
	sum += b - 1;
	sum %= 7;
	answer = day[sum];
	return answer;
}

int main(void)
{
	int a = 5, b = 24;
	cout << solution(a, b);
	return 0;
}