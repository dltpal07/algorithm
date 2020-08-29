//https://www.acmicpc.net/problem/5052


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int T, n;
	bool is_print;
	cin >> T;
	while (T--)
	{
		vector<string> v;
		is_print = false;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i].size() > v[i + 1].size())
				continue;
			if (v[i + 1].substr(0, v[i].size()) == v[i])
			{
				cout << "NO\n";
				is_print = true;
				break;
			}
		}
		if (!is_print)
		{
			cout << "YES\n";
		}
	}
	return 0;
}