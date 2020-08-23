//https://www.acmicpc.net/problem/11006


#include <iostream>

using namespace std;

int main(void)
{
	int t, l, c, ans1, ans2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> l >> c;
		ans1 = 2 * c - l;
		ans2 = c - ans1;
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}