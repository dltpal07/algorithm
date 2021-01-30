//https://programmers.co.kr/learn/courses/30/lessons/12987


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0, j = 0, st = 0, cnt = 0;
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());

	int i = 0;
	while (i < A.size() && j < B.size())
	{
		if (A[i] < B[j])
		{
			cnt++;
			j++;
		}
		i++;
	}
	answer = cnt;
	return answer;
}

int main(void)
{
	vector<int> A1 = { 5, 1, 3, 7 }, B1 = { 2, 2, 6, 8 };
	vector<int> A2 = { 2, 2, 2, 2 }, B2 = { 1, 1, 1, 1 };
	cout << solution(A2, B2);
	return 0;
}