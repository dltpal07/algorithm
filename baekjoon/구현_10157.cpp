//https://www.acmicpc.net/problem/10157


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int C, R, K, i, j = 0, cnt = 1, max_i, max_j, min_i, min_j;
	cin >> C >> R >> K;
	i = R;
	max_j = C;
	max_i = R;
	min_i = 0;
	min_j = 0;
	if (K > R*C)
	{
		cout << 0;
		return 0;
	}
	vector<vector<int>> board(R, vector<int>(C));
	while (1)
	{
		i--;
		while (i >= min_i)
		{
			board[i][j] = cnt;
			if (cnt == K)
				goto finish;
			cnt++;
			i--;
		}
		min_i++;
		i++;
		j++;
		while (j < max_j)
		{
			board[i][j] = cnt;
			if (cnt == K)
				goto finish;
			cnt++;
			j++;
		}
		j--;
		max_j--;
		i++;
		while (i < max_i)
		{
			board[i][j] = cnt;
			if (cnt == K)
				goto finish;
			cnt++;
			i++;
		}
		i--;
		max_i--;
		j--;
		while (j > min_j)
		{
			board[i][j] = cnt;
			if (cnt == K)
				goto finish;
			cnt++;
			j--;
		}
		min_j++;
		j++;
	}
finish:
	cout << j + 1 << " " << R - i;
	return 0;
}