// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

// 세로 크기, 가로 크기, 세로 위치, 가로 위치, 소요된 시간

int N, M, R, C, L;
int hole[51][51] = { 0, };
int visited[51][51] = { 0, };
// x, y 상 하 좌 우
int direct[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
map<int, vector<int>> m = { {0, {}}, {1, {0, 1, 2, 3}}, {2, {0, 1}}, {3, {2, 3}}, {4, {1, 3}}, {5, {0, 3}}, {6, {0, 2}}, {7, {1, 2}} };
map<int, int> check_m = { {0, 1}, {1, -1}, {2, 2}, {3, -2} };
struct Point {
	int x, y, lv;
};

queue<Point> q;
int answer = 0;



void BFS()
{
	int nx, ny;
	Point cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (auto i : m[hole[cur.y][cur.x]])
		{
			nx = cur.x + direct[i][0];
			ny = cur.y + direct[i][1];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && cur.lv < L)
			{
				for (auto check_coord : m[hole[ny][nx]])
				{
					if (check_m[i] + check_m[check_coord] == 0)
					{
						visited[ny][nx] = 1;
						q.push({ nx, ny, cur.lv + 1 });
						answer++;
					}
				}
				
			}
		}
		
	}
}


int main(int argc, char** argv)
{
	int T;
	int test_case;
	int nx, ny, max_val = 0;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(hole, 0, sizeof(hole));
		memset(visited, 0, sizeof(visited));
		answer = 0;
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> hole[i][j];
			}
		}
		q.push({ C, R, 1 });
		BFS();
		if (answer == 0)
			answer = 1;
		cout << "#" << test_case << " " << answer << endl;
	}

		
	return 0;
}
