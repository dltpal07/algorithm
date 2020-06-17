//https://www.acmicpc.net/problem/10814


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int N,age;
	string name;
	vector<pair<int, string>> s;
	vector<pair<int, int>> comp;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		s.push_back({ age, name });
		comp.push_back({ age, i });
	}
	sort(comp.begin(), comp.end());
	for (int i = 0; i < N; i++)
	{
		cout << s[comp[i].second].first << " " << s[comp[i].second].second<<"\n";
	}
	return 0;
}
