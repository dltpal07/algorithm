//https://www.acmicpc.net/problem/11656


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	vector<string> v;
	for (int i = 0; i < str.size(); i++)
	{
		v.push_back(str.substr(i, str.size() - i));
	}
	sort(v.begin(), v.end());
	for (auto x : v)
	{
		cout << x << "\n";
	}
	return 0;
}