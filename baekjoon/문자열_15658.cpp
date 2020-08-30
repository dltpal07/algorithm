//https://www.acmicpc.net/problem/15658


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> try_oper;
string tmp;
char oper_list[4] = { '+','-','*','/' };
int all_cnt = 0;
int n, oper[4];
void DFS(int cnt)
{
	if (cnt == n-1)
	{
		try_oper.push_back(tmp);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			oper[i]--;
			tmp += oper_list[i];
			DFS(++cnt);
			cnt--;
			oper[i]++;
			tmp = tmp.substr(0, tmp.size() - 1);
		}
	}

}


int main(void)
{
	cin >> n;
	vector<long long> v(n);
	long long sum = 0, min_val = 1000000000, max_val = -1000000000;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
		all_cnt += oper[i];
	}
	DFS(0);
	
	for (int t = 0; t < try_oper.size(); t++)
	{
		sum = v[0];
		for (int i = 0; i < n - 1; i++)
		{
			if (try_oper[t][i] == '+')
			{
				sum += v[i + 1];
			}
			else if (try_oper[t][i] == '-')
			{
				sum -= v[i + 1];
			}
			else if (try_oper[t][i] == '*')
			{
				sum *= v[i + 1];
			}
			else if (try_oper[t][i] == '/')
			{
				sum /= v[i + 1];
			}
		}
		
		if (min_val > sum)
		{
			min_val = sum;
		}
		if (max_val < sum)
		{
			max_val = sum;
		}
	}
	cout << max_val << endl << min_val;
	return 0;
}