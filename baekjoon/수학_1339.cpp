//https://www.acmicpc.net/problem/1339


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int dict[26] = { 0 }, e = 1, sum = 0;
	cin >> N;
	vector<string> str(N);
	

	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	
	for (int i = 0; i < str.size(); i++)
	{
		e = 1;
		for (int j = str[i].size() - 1; j >= 0; j--)
		{
			dict[str[i][j] - 'A'] += e;
			e *= 10;
		}
	}
	
	sort(dict, dict + 26, greater<>());
	for (int i = 0; i < 10; i++)
	{
		sum += dict[i] * (9 - i);
	}
	cout << sum;
	return 0;
}