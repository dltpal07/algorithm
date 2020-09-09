//https://www.acmicpc.net/problem/2257


#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main(void)
{
	int stack[100] = {0}, cnt = 0;
	int tmp = 0;
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (ch == 'H')
		{
			tmp = 1;
			stack[cnt] += 1;
		}
		else if (ch == 'C')
		{
			tmp = 12;
			stack[cnt] += 12;
		}
		else if (ch == 'O')
		{
			tmp = 16;
			stack[cnt] += 16;
		}
		else if (ch == '(')
		{
			stack[++cnt] = 0;
		}
		else if (ch == ')')
		{
			tmp = stack[cnt--];
			stack[cnt] += tmp;
		}
		else if ('2' <= ch && ch <= '9')
		{
			stack[cnt] += tmp * (ch - '1');
		}
	}
	cout << stack[0];
	return 0;
}