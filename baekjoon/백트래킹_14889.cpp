//https://www.acmicpc.net/problem/14889


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl "\n"
#define MAX 11

vector<vector<int>> x;
vector<int> choice, not_choice;

int N, min_val = 987654321;
void Input()
{
	int a;
	for (int i = 0; i < N; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			tmp.push_back(a);
		}
		x.push_back(tmp);
	}
}

void DFS(int cnt, int cur)
{
	static vector<bool> check(N,false);

	int a_sum = 0, b_sum = 0;
	if (cnt == N / 2) // 점수 계산
	{
		not_choice.clear();
		for (int i = 0; i < N; i++)
		{
			if (find(choice.begin(), choice.end(), i) == choice.end())
				not_choice.push_back(i);
		}
		for (auto i : choice)
		{
			for (auto j : choice)
			{
				a_sum += x[i][j];
			}
		}
		for (auto i : not_choice)
		{
			for (auto j : not_choice)
			{
				b_sum += x[i][j];
			}
		}
		
		if (abs(a_sum - b_sum) < min_val)
		{
			min_val = abs(a_sum - b_sum);
		}
		
		return;
	}
	for (int i = cur; i < N; i++) // 고르기만
	{
		if (check[i] == false)
		{	
			choice.push_back(i);
			check[i] = true;
			DFS(cnt + 1,i);
			choice.pop_back();
			check[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	Input();
	DFS(0,0);
	cout << min_val;
	return 0;
}