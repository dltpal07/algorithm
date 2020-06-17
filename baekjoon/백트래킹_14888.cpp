//https://www.acmicpc.net/problem/14888


#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
#define MAX 11
int N, _max = -987654321, _min = 987654321, oper[4] = { 0 };
vector<int> num(MAX), new_op;
string poly;
int compute()
{
	int result = 0, i = 0;
	vector<int> temp(N),temp_op;
	temp = num;
	temp_op = new_op;
	while(1)
	{
		if (temp_op.size() == 0)
			break;
		

		if (temp_op[0]== 0)
		{

			temp[i] = temp[i] + temp[i + 1];
			temp.erase(temp.begin() + i + 1);
		}
		else if(temp_op[0] ==1)
		{

			temp[i] = temp[i] - temp[i + 1];
			temp.erase(temp.begin() + i + 1);
		}

		else if (temp_op[0] == 2)
		{
			temp[i] = temp[i] * temp[i + 1];
			temp.erase(temp.begin() + i + 1);
		}
		else
		{
			
			temp[i] = temp[i] / temp[i + 1];
			temp.erase(temp.begin() + i + 1);
		}
		temp_op.erase(temp_op.begin());
	}
	return temp[0];
}
void DFS(int cnt)
{
	int cur = 0;
	int result = 0;
	if (cnt >= N - 1)
	{
		result = compute();
		if (result > _max)
		{
			_max = result;
		}
		if (result < _min)
		{
			_min = result;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i] != 0)
		{
			new_op.push_back(i);
			oper[i]--;
			DFS(cnt + 1);
			new_op.pop_back();
			oper[i]++;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	DFS(0);
	cout << _max << "\n" << _min;
	return 0;
}