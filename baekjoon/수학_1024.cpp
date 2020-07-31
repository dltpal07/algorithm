//https://www.acmicpc.net/problem/1024


#include <iostream>

using namespace std;

int main(void)
{
	long long n, l, tmp, answer;
	int add_num = -1;
	cin >> n >> l;
	
	for(int i=l;i<=100;i++)
	{
		tmp = n - (i * (i - 1)) / 2;
		if (tmp>=0&&tmp%i == 0)
		{
			answer = tmp / i;
			add_num = i;
			break;
		}
		
	}
	if (add_num == -1)
	{
		cout << -1;
	}
	else
	{
		for (int t = 0; t < add_num; t++)
		{
			cout << t + answer << " ";
		}
	}
	return 0;
}