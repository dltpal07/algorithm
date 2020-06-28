//https://www.acmicpc.net/problem/1697


#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 100001
int N, K;
bool visit[MAX];

int BFS(int N, int K)
{
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visit[N] = true;

	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		
		q.pop();
		
		if (pos == K)
			return time;
		if (pos + 1 < MAX && visit[pos + 1] == false)
		{
			q.push({ pos + 1, time + 1 });
			visit[pos + 1] = true;
		}
		if (pos - 1 >=0 && visit[pos - 1] == false)
		{
			q.push({ pos - 1, time + 1 });
			visit[pos - 1] = true;
		}
		if (pos * 2 < MAX && visit[pos * 2] == false)
		{
			q.push({ pos * 2, time + 1 });
			visit[pos * 2] = true;
		}

	}
}


int main(void)
{
	cin >> N >> K;
	
	cout << BFS(N, K);
	return 0;
}