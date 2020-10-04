//https://programmers.co.kr/learn/courses/30/lessons/12953


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int solution(vector<int> arr)
{
	int answer = 0;
	answer = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		answer = lcm(answer, arr[i]);
	}
	return answer;
}

int main(void)
{
	vector<int> arr1 = { 2,6,8,14 }, arr2 = { 1,2,3 };
	cout << solution(arr2);
	return 0;
}