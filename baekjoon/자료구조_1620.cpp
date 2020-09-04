//https://www.acmicpc.net/problem/1620


#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int, string> m1;
	map<string, int> m2;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string tmp;
		cin >> tmp;
		m1.insert({ i, tmp });
		m2.insert({ tmp, i });
	}
	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] >= '0'&&tmp[0] <= '9')
		{
			int num = stoi(tmp);
			cout << m1[num]<<"\n";
		}
		else
		{
			cout << m2[tmp] << "\n";
		}
	}
	return 0;
}