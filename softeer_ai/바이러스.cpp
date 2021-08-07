//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=407


#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
	long long answer = 1;
	int K, P, N;
	cin >> K >> P >> N;
	answer = K;
	for (int i = 0; i < N; i++)
	{
		answer *= P;
		answer %= 1000000007;
	}
	cout << answer;
	return 0;
}