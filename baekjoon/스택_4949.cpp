//https://www.acmicpc.net/problem/4949


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
char stack[100];

int  st = 0, ed = 0;
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
	bool isPrint = false, isPush = false;
	int N, tmp, sum=0;
	vector<string> s;
	string t;
	while (1)
	{
		getline(cin, t);
		
		if (t.size()==1 && t == ".")
			break;
		s.push_back(t);
	}
	
	for (int k = 0; k < s.size(); k++)
	{
		isPrint = false;
		isPush = false;
		st = 0;
		ed = 0;
		for (int i = 0; i < s[k].size(); i++)
		{
			if (s[k][i] == '(' || s[k][i] == '[')
			{
				isPush = true;
				push(s[k][i]);
			}
			
			else if (s[k][i] == ')' || s[k][i] == ']')
			{
				if (ed == st)
				{
					cout << "no\n";
					isPrint = true;
					break;
				}
				else
				{
					if (s[k][i] == ')')
					{
						if (stack[ed] == '(')
							pop();
						else
						{
							cout << "no\n";
							isPrint = true;
							break;
						}
					}
					else 
					{
						if (stack[ed] == '[')
							pop();
						else
						{
							cout << "no\n";
							isPrint = true;
							break;
						}
					}
				}
			}
			
		}
		if (isPrint == false)
		{
			if (isPush == false)
			{
				cout << "yes\n";
			}
			else
			{
				if (st == ed)
				{
					cout << "yes\n";
				}
				else
				{
					cout << "no\n";
				}
			}
		}
	}
	return 0;
}