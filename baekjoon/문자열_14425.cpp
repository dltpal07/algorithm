//https://www.acmicpc.net/problem/14425


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, cnt = 0;
	cin >> N >> M;
	vector<string> origin;
	map<string, int> comp;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		origin.push_back(tmp);
	}
	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		comp[tmp]++;
	}
	for (auto x:comp)
	{
		if (find(origin.begin(), origin.end(), x.first) != origin.end())
		{
			cnt += x.second;
		}
	}
	cout << cnt;
	return 0;
}