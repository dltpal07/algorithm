//https://www.acmicpc.net/problem/1075


#include <iostream>

using namespace std;

int main(void)
{
	int N, F, M, answer;
	cin >> N >> F;
	M = N / 100 * 100;
	if (M%F == 0)
		answer = 0;
	else
	{
		M += (F - M % F);
		answer = M % 100;
	}
	if (answer < 10)
		cout << 0 << answer;
	else
		cout << answer;
	return 0;
}