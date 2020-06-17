//https://www.acmicpc.net/problem/15650


#include <iostream>

using namespace std;

#define MAX 8+1
int n, m;
int lists[MAX];
bool check[MAX] = { 0 };

void dfs(int cnt,int cur)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << lists[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cur; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			lists[cnt] = i;
			dfs(cnt + 1,i+1);
			check[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(0,1);
	return 0;
}