//https://programmers.co.kr/learn/courses/30/lessons/12941


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[B.size() - i - 1];
	}
	return answer;
}

int main(void)
{
	vector<int> A1 = { 1, 4, 2 }, B1 = { 5, 4, 4 }, A2 = { 1, 2 }, B2 = { 3, 4 };
	cout << solution(A2, B2);
	return 0;
}