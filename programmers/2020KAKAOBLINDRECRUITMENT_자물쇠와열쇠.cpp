//https://programmers.co.kr/learn/courses/30/lessons/60059


#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>> v, int ls)
{
	for (int i = ls; i < 2 * ls; i++)
	{
		for (int j = ls; j < 2 * ls; j++)
		{
			if (v[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = true;
	int ks = key.size();
	int ls = lock.size();
	vector<vector<int>> key90, key180, key270;
	vector<vector<int>> big_lock;

	
	for (int i = 0; i < 3 * ls; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 3 * ls; j++)
		{
			if ((i >= ls && i < 2 * ls) && (j >= ls && j < 2 * ls))
				tmp.push_back(lock[i - ls][j - ls]);
			else
				tmp.push_back(0);

		}
		big_lock.push_back(tmp);
	}
	

	for (int j = 0; j < ks; j++)
	{
		vector<int> tmp;
		for (int i = ks - 1; i >= 0; i--)
		{
			tmp.push_back(key[i][j]);
		}
		key90.push_back(tmp);
	}
	for (int j = 0; j < ks; j++)
	{
		vector<int> tmp;
		for (int i = ks - 1; i >= 0; i--)
		{
			tmp.push_back(key90[i][j]);
		}
		key180.push_back(tmp);
	}
	for (int j = 0; j < ks; j++)
	{
		vector<int> tmp;
		for (int i = ks - 1; i >= 0; i--)
		{
			tmp.push_back(key180[i][j]);
		}
		key270.push_back(tmp);
	}

	vector<vector<vector<int>>> keys;
	keys.push_back(key);
	keys.push_back(key90);
	keys.push_back(key180);
	keys.push_back(key270);
	
	for (auto k : keys)
	{
		for (int i = 0; i < big_lock.size(); i++)
		{
			for (int j = 0; j < big_lock.size(); j++)
			{
				vector<vector<int>> tmp_lock = big_lock;
				for (int cur_i = 0; cur_i < ks; cur_i++)
				{
					for (int cur_j = 0; cur_j < ks; cur_j++)
					{
						if (i + cur_i >= 3 * ls || j + cur_j >= 3 * ls)
							break;
						if (tmp_lock[i + cur_i][j + cur_j] == 1 && k[cur_i][cur_j] == 1)
							break;
						else
							tmp_lock[i + cur_i][j + cur_j] += k[cur_i][cur_j];
					}
				}
				answer = check(tmp_lock, ls);
				if (answer == true)
					return answer;
			}
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	cout << solution(key, lock);
	return 0;
}