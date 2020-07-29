//https://www.acmicpc.net/problem/9506


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n,  sum = 0, cnt = 0;
	
	while (1)
	{
		cin >> n;
		if (n == -1)
		{
			break;
		}
		vector<int> p_num;
		sum = 0;
		
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				p_num.push_back(i);
				sum += i;
				cnt++;
			}
		}
		
		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < p_num.size() - 1; i++)
			{
				cout << p_num[i] << " + ";
			}
			cout << p_num[p_num.size() - 1]<<"\n";
		}
		else
		{
			cout << n << " is NOT perfect.\n";
		}
	}
	return 0;
}