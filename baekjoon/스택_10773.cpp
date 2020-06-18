//https://www.acmicpc.net/problem/10773


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int stack[100000], st=0, ed=0;
void push(int tmp)
{
	ed++;
	stack[ed] = tmp;
	
}

void pop()
{
	int rt = stack[ed];
	stack[ed] = 0;
	ed--;
}

int size()
{
	return ed - st;
}

int main(void)
{
	int N, tmp, sum=0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			pop();
		}
		else
		{
			push(tmp);
		}
	}
	for (int i = st; i <= ed; i++)
	{
		sum += stack[i];
	}
	cout << sum;
	return 0;
}