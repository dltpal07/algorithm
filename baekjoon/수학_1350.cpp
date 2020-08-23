//https://www.acmicpc.net/problem/1350


#include <iostream>

using namespace std;

int main(void)
{
	long long file[1000], answer = 0, tmp;
	int n, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> file[i];
	}
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		if (file[i] == 0)
			continue;
		if (file[i] % c == 0)
			tmp = file[i] / c;
		else
			tmp = file[i] / c + 1;
		answer += tmp * c;
	}
	cout << answer;
	return 0;
}