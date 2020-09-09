//https://www.acmicpc.net/problem/17608


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	stack<int> s;
	s.push(v[N - 1]);
	for (int i = N - 2; i >= 0; i--)
	{
		if (v[i] > s.top())
		{
			s.push(v[i]);
		}
	}
	cout << s.size();
	return 0;
}