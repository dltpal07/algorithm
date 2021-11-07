//https://programmers.co.kr/learn/courses/30/lessons/87946


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
	vector<int> v;
	for (int i = 0; i < dungeons.size(); i++)
	{
		v.push_back(i);
	}
	int result = 0;
	while (next_permutation(v.begin(), v.end()))
	{
		int tmp_k = k;
		int cnt = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int min_val = dungeons[v[i]][0];
			int used_val = dungeons[v[i]][1];
			
			if (min_val > tmp_k)
				continue;

			tmp_k -= used_val;
			cnt++;
		}
		result = max(result, cnt);
	}
	return result;
}

int main(void)
{
	int k = 80;
	vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
	cout << solution(k, dungeons);
	return 0;
}