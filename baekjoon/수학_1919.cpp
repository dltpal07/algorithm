//https://www.acmicpc.net/problem/1919


#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int sum = 0;
	string str1, str2;
	map<char, int> m1, m2;
	cin >> str1 >> str2;
	for (char i = 'a'; i <= 'z'; i++)
	{
		int cnt1, cnt2;
		cnt1 = count(str1.begin(), str1.end(), i);
		cnt2 = count(str2.begin(), str2.end(), i);
		m1[i] = cnt1;
		m2[i] = cnt2;
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		sum += abs(m1[i] - m2[i]);
	}
	cout << sum;
	return 0;
}