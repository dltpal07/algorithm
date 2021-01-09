//https://programmers.co.kr/learn/courses/30/lessons/70128


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int answer = 0;
	for (int i = 0; i < a.size(); i++)
	{
		answer += a[i] * b[i];
	}
	return answer;
}

int main(void)
{
	vector<int> a1 = { 1, 2, 3, 4 }, b1 = { -3, -1, 0, 2 }, a2 = { -1, 0, 1 }, b2 = { 1, 0, -1 };
	cout << solution(a1, b1);
	return 0;
}