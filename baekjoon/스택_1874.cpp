//https://www.acmicpc.net/problem/1874


#include <iostream>
#include <vector>
using namespace std;
int stack[100000] = { 0 };
int ed = 0;
vector<char> result;
void push(int tmp)
{
	ed++;
	stack[ed] = tmp;
	result.push_back('+');
}

void pop()
{
	stack[ed] = 0;
	ed--;
	result.push_back('-');
}

int main(void)
{
	bool isPrint = false;
	int n, cur = 1;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (stack[ed] == x[i])
		{
			pop();
		}
		else if (stack[ed] < x[i])
		{
			while (1)
			{
				push(cur);
				if (cur == x[i])
				{
					pop();
					cur++;
					break;
				}
				cur++;
			}
		}
		else
		{
			cout << "NO\n";
			isPrint = true;
			break;
		}
	}
	if (!isPrint)
	{
		for (auto k : result)
		{
			cout << k << "\n";
		}
	}
	return 0;
}