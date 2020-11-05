//https://programmers.co.kr/learn/courses/30/lessons/17687


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int, char> dict;

string get_decimal(int num, int d)
{
	string s = "";
	
	while (num > 0)
	{
		s += dict[num%d];
		num /= d;
	}
	reverse(s.begin(), s.end());
	return s;
}

string solution(int n, int t, int m, int p)
{
	string answer = "0";
	string real_answer = "";
	int minimum;
	minimum = m * (t - 1) + p;
	int num = 1;
	for (int i = 0; i <= 15; i++)
	{
		if (i < 10)
			dict[i] = '0' + i;
		else
			dict[i] = 'A' + i - 10;
	}
	while (1)
	{
		if (answer.size() > minimum)
		{
			break;
		}
		answer += get_decimal(num, n);
		num++;
	}
	for (int i = p - 1, tmp = 0; tmp < t; i = i+m, tmp++)
	{
		real_answer += answer[i];
	}
	return real_answer;
}

int main(void)
{
	int n1 = 2, t1 = 4, m1 = 2, p1 = 1, n2 = 16, t2 = 16, m2 = 2, p2 = 1;
	int n3 = 16, t3 = 16, m3 = 2, p3 = 2;
	cout << solution(n3, t3, m3, p3);
	return 0;
}