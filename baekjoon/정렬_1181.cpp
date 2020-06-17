//https://www.acmicpc.net/problem/1181


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, len = 1,i=0;
	string str, temp;
	vector<string> s;
	vector<pair<int, string>> comp;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		comp.push_back({ strlen(str.c_str()),str });
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (auto x : comp)
	{
		cout<< x.second << endl;
	}
	return 0;
}
