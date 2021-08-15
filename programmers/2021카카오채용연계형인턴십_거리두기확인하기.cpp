//https://programmers.co.kr/learn/courses/30/lessons/81302


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;
	for (int t = 0; t < places.size(); t++)
	{
		int cnt = 0;
		for (int i = 0; i < places[t].size(); i++)
		{
			for (int j = 0; j < places[t][i].size(); j++)
			{
				if (places[t][i][j] == 'P')
				{
					if (j+1 < places[t][i].size() && places[t][i][j + 1] == 'P')
						cnt++;
					if (i+1 < places[t].size() && places[t][i + 1][j] == 'P')
						cnt++;
					if (j+2 < places[t][i].size() && places[t][i][j + 1] == 'O' && places[t][i][j + 2] == 'P')
						cnt++;
					if (i+2 < places[t].size() && places[t][i + 1][j] == 'O' && places[t][i + 2][j] == 'P')
						cnt++;
					if (i + 1 < places[t].size() && j + 1 < places[t][i].size() && places[t][i + 1][j + 1] == 'P' && (places[t][i + 1][j] == 'O' || places[t][i][j + 1] == 'O'))
						cnt++;
					if (i + 1 < places[t].size() && j - 1 >= 0 && places[t][i + 1][j - 1] == 'P' && (places[t][i][j - 1] == 'O' || places[t][i + 1][j] == '0'))
						cnt++;
					if (i - 1 >= 0 && j + 1 < places[t][i].size() && places[t][i - 1][j + 1] == 'P' && (places[t][i - 1][j] == 'O' || places[t][i][j + 1] == 'O'))
						cnt++;
					if (i - 1 >= 0 && j - 1 >= 0 && places[t][i - 1][j - 1] == 'P' && (places[t][i - 1][j] == 'O' || places[t][i][j - 1] == 'O'))
						cnt++;
				}
			}
			
		}
		if (cnt != 0)
		{
			answer.push_back(0);
		}
		else
		{
			answer.push_back(1);
		}
	}
	return answer;
}

int main(void)
{
	vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
	vector<int> answer = solution(places);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}
