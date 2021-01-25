//https://programmers.co.kr/learn/courses/30/lessons/12938


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s)
{
	vector<int> answer;
	int mod = s / n;
	int res = s % n;
	if (s < n)
		return vector<int>(1, -1);
	vector<int> v(n, mod);
	for (int i = 0; i < res; i++)
	{
		v[i]++;
	}
	sort(v.begin(), v.end());
	answer = v;
	return answer;
}

int main(void)
{
	int n1 = 2, s1 = 9, n2 = 2, s2 = 1, n3 = 2, s3 = 8;
	vector<int> answer = solution(n3, s3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}