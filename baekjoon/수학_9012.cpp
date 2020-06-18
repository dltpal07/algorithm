//https://www.acmicpc.net/problem/9012


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
char stack[50];
int  st=0, ed=0;
void push(char tmp)
{
	ed++;
	stack[ed] = tmp;
	
}

void pop()
{
	if (ed - st > 0)
	{
		stack[ed] = 0;
		ed--;
	}
}

int main(void)
{
	bool isPrint = false;
	int N, tmp, sum=0;
	cin >> N;
	string s;
	
	for (int k = 0; k < N; k++)
	{
		isPrint = false;
		st = 0;
		ed = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				push(s[i]);
			}
			else if(s[i]==')')
			{
				if (ed - st == 0)
				{
					cout << "NO" << "\n";
					isPrint = true;
					break;
				}
				else 
				{
					pop();
				}
			}
		}
		if (!isPrint)
		{
			if (ed - st > 0)
			{
				cout << "NO" << "\n";
			}
			else
			{
				cout << "YES\n";
			}
		}
		
	}
	return 0;
}