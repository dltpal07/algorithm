//https://programmers.co.kr/learn/courses/30/lessons/17679


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	vector<vector<char>> vs;
	for (int i = 0; i < board.size(); i++)
	{
		vector<char> s;
		for (int j = 0; j < board[i].size(); j++)
		{
			s.push_back(board[i][j]);
		}
		vs.push_back(s);
	}
	while (1)
	{
		int cnt = 0;
		vector<vector<int>> checked(m, vector<int>(n, 0));
		for (int i = 0; i < vs.size() - 1; i++)
		{
			for (int j = 0; j < vs[i].size() - 1; j++)
			{
				if (vs[i][j]!='0'&&vs[i][j] == vs[i + 1][j] && vs[i][j] == vs[i][j + 1] && vs[i][j] == vs[i + 1][j + 1])
				{
					cnt++;
					checked[i][j] = 1;
					checked[i][j + 1] = 1;
					checked[i + 1][j] = 1;
					checked[i + 1][j + 1] = 1;
				}
			}
		}
		for(int i=0;i<checked.size();i++)
			answer += count(checked[i].begin(), checked[i].end(), 1);
	
		for (int i = 0; i < checked.size(); i++)
		{
			for (int j = 0; j < checked[i].size(); j++)
			{
				if (checked[i][j] == 1)
				{
					vs[i][j] = '0';
				}
			}
		}
		for (int i = vs.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < vs[i].size(); j++)
			{
				if (vs[i][j] == '0')
				{
					int t = i;
					while (1)
					{
						if (t<0 || (vs[t][j]!='0'))
						{
							break;
						}
						t--;
					}
					if (t < 0)
						vs[i][j] = '0';
					else
					{
						vs[i][j] = vs[t][j];
						vs[t][j] = '0';
					}

				}
				
			}
		}
		
		
		if (cnt == 0)
			break;
	}
	
	return answer;
}

int main(void)
{
	int m1 = 4, n1 = 5, m2 = 6, n2 = 6;
	vector<string> board1 = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	vector<string> board2 = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	cout << solution(m2, n2, board2);
	return 0;
}