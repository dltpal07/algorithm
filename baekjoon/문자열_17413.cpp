//https://www.acmicpc.net/problem/17413


#include <iostream>
#include <string>
using namespace std;
string str, answer = "";
int i;
void forward()
{

	while (1)
	{
		
		answer += str[i];
		if (str[i] == '>')
		{
			i = i + 1;
			break;
		}
		i++;
	}
}

void backward()
{
	int j = i;
	while (j < str.size())
	{
		if (str[j] == '<' || str[j] == ' ')
		{
			break;
		}
		j++;
	}
	for (int k = j - 1; k >= i; k--)
	{
		answer += str[k];
	}
	i = j;
}

int main(void)
{
	i = 0;
	getline(cin, str);
	while (i<str.size())
	{
		if (str[i] == '<')
		{
			forward();
		}
		else if (str[i] == ' ')
		{
			answer += ' ';
			i++;
		}
		else
		{
			backward();
		}

	}
	cout << answer;
	return 0;
}