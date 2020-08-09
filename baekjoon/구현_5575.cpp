//https://www.acmicpc.net/problem/5575


#include <iostream>

using namespace std;

int main(void)
{
	int b1, b2, b3, a1, a2, a3, ans1, ans2, ans3;
	for (int i = 0; i < 3; i++)
	{
		cin >> b1 >> b2 >> b3 >> a1 >> a2 >> a3;
		ans3 = a3 - b3;
		if (ans3 < 0)
		{
			ans3 += 60;
			a2--;
		}
		ans2 = a2 - b2;
		if (ans2 < 0)
		{
			ans2 += 60;
			a1--;
		}
		ans1 = a1 - b1;

		cout << ans1 << " " << ans2 << " " << ans3<<"\n";
	}
	return 0;
}