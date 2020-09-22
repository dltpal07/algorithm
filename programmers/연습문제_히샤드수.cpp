//https://programmers.co.kr/learn/courses/30/lessons/12947


#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
	bool answer = true;
	int sum = 0;
	int n = x;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	if (x%sum == 0)
		answer = true;
	else
		answer = false;
	return answer;
}

int main(void)
{
	int arr1 = 10, arr2 = 12, arr3 = 11, arr4 = 13;
	cout << solution(arr4);
	return 0;
}