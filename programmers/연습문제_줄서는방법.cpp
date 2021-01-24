//https://programmers.co.kr/learn/courses/30/lessons/12936


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int checked[21] = { 0 };

long long factorial(int n)
{
	long long ans = 1;
	while (n > 0)
	{
		ans *= n;
		n--;
	}
	return ans;
}

vector<int> solution(int n, long long k)
{
	vector<int> answer;
	long long mod;
	int all = 20;
	for (int i = n - 1; i >= 1; i--)
	{
		long long fact = factorial(i);
		int cnt = 1;
		while (cnt * fact < k)
		{
			cnt += 1;
		}
		int tmp = 0;
		int idx = 0;
		for (int j = 1; j <= n; j++)
		{
			if (checked[j] == 0)
				tmp++;
			if (tmp == cnt)
			{
				idx = j;
				break;
			}
		}
		answer.push_back(idx);
		checked[idx] = 1;
		k = k % fact;
		if (k == 0)
			k += fact;
	}
	for (int i = 1; i <= n; i++)
	{
		if (checked[i] == 0)
		{
			answer.push_back(i);
		}
	}
	
	return answer;
}

int main(void)
{
	int n =20, k = 10;
	vector<int> answer = solution(n, k);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}