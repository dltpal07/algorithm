//https://www.acmicpc.net/problem/2804


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string A, B;
	int idx1, idx2;
	vector<vector<char>> v;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				idx1 = i;
				idx2 = j;
				goto finish;
			}
		}
	}
finish:
	for (int i = 0; i < B.size(); i++)
	{
		vector<char> tmp;
		if (i == idx2)
		{
			for (int j = 0; j < A.size(); j++)
			{
				tmp.push_back(A[j]);
			}
		}
		else
		{
			for (int j = 0; j < A.size(); j++)
			{
				if (j == idx1)
				{
					tmp.push_back(B[i]);
				}
				else
				{
					tmp.push_back('.');
				}
			}
		}
		v.push_back(tmp);
	}
	for (auto x : v)
	{
		for (auto y : x)
		{
			cout << y;
		}
		cout << endl;
	}
	return 0;
}