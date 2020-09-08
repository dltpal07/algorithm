//https://www.acmicpc.net/problem/7567


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int answer = 0;
	string str;
	cin >> str;
	char ch = str[0];
	answer += 10;
	for (int i = 1; i < str.size(); i++)
	{
		if (ch == str[i])
			answer += 5;
		else
		{
			answer += 10;
			ch = str[i];
		}
	}
	cout << answer;
	return 0;
}