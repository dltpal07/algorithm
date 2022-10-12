//https://swexpertacademy.com/main/code/problem/problemDetail.do


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		set<string> s;
		string str;
		int N, K;
		cin >> N >> K;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			string tmp_str = "";
			tmp_str += str.substr(i, str.size());
			tmp_str += str.substr(0, i);
			int tmp_size = tmp_str.size() / 4;
			for (int j = 0; j < 4; j++)
			{
				string key = tmp_str.substr(j * tmp_size, tmp_size);
				s.insert(key);
			}
			
		}
		vector<string> sv(s.begin(), s.end());
		unsigned long long hex = stoul(sv[sv.size() - K], nullptr, 16);
		cout << "#" << test_case << " " << hex << "\n";
	}
	return 0;
}
