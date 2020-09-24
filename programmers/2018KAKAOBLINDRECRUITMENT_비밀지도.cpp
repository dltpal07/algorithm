//https://programmers.co.kr/learn/courses/30/lessons/17681


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;
	int a, b, num1, num2;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		string last = "";
		num1 = arr1[i];
		num2 = arr2[i];
		for (int j = 0; j < n; j++)
		{
			a = num1 % 2;
			b = num2 % 2;
			if (a|b == 1)
			{
				str += '#';
			}
			else
			{
				str += ' ';
			}
			num1 = num1 >> 1;
			num2 = num2 >> 1;
		}
		for (int j = n - 1; j >= 0; j--)
		{
			last += str[j];
		}
		answer.push_back(last);
	}
	return answer;
}

int main(void)
{
	int n1 = 5;
	vector<int> arr11 = { 9, 20, 28, 18, 11 }, arr12 = { 30, 1, 21, 17, 28 };
	vector<string> answer = solution(n1, arr11, arr12);
	for (auto x : answer)
	{
		cout << x << endl;
	}
	return 0;
}