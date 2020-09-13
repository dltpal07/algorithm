//https://programmers.co.kr/learn/courses/30/lessons/12922


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
	string answer = "";
	string s[2] = { "수", "박" };
	for (int i = 0; i < n; i++)
	{
		answer += s[i % 2];
	}
	return answer;
}

int main(void)
{
	int n1 = 3, n2 = 4;
	cout << solution(n2);
	return 0;
}