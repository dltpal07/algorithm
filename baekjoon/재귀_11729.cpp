//https://www.acmicpc.net/problem/11729


#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
void Hanoi(int num, int from, int by, int to)
{
	if (num == 1)
		v.push_back({ from, to });
	else
	{
		Hanoi(num - 1, from, to, by);
		v.push_back({ from, to });
		Hanoi(num - 1, by, from, to);
	}
}
int main(void)
{
	int N;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	Hanoi(N, 1, 2, 3);
	cout << v.size()<<"\n";
	for (auto x : v)
	{
		cout << x.first << " " << x.second << "\n";
	}
	return 0;
}