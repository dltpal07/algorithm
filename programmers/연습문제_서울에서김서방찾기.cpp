//https://programmers.co.kr/learn/courses/30/lessons/12919


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul)
{
	string answer = "";
	int i;
	i = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
	string c = to_string(i);
	answer = "김서방은 " + c + "에 있다";
	return answer;
}

int main(void)
{
	vector<string> seoul = { "Jane", "Kim" };
	string answer = solution(seoul);
	cout << answer;
	return 0;
}