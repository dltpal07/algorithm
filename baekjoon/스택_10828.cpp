//https://www.acmicpc.net/problem/10828


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int stack[10000], st=0, ed=0;
void push(int tmp)
{
	ed++;
	stack[ed] = tmp;
	
}

int pop()
{
	if (st == ed)
		return -1;
	else
	{
		int rt = stack[ed];
		stack[ed] = 0;
		ed--;
		return rt;
	}
}

int size()
{
	return ed - st;
}

int empty()
{
	if (st == ed)
		return 1;
	else
		return 0;
}

int top()
{
	if (st == ed)
		return -1;
	else
		return stack[ed];
}

int main(void)
{
	int N, tmp;
	string s;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> tmp;
			push(tmp);
		}
		else if (s == "pop")
		{
			cout << pop()<<"\n";
		}
		else if (s == "size")
		{
			cout << size()<<"\n";
		}
		else if (s == "empty")
		{
			cout << empty() << "\n";
		}
		else if (s == "top")
		{
			cout << top() << "\n";
		}
	}
	return 0;
}