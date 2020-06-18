//https://www.acmicpc.net/problem/11866


#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	int n, k, cur = - 1;
	cin >> n >> k;
	vector<int> x;
	for (int i = 1; i <= n; i++)
	{
		x.push_back(i);
	}
	cout << '<';
	while (1)
	{
		if (x.empty())
			break;
		cur += k;
		if (cur >= x.size())
		{
			while (1)
			{
				cur -= x.size();
				if (cur < x.size())
					break;
			}
		}
		if (x.size() > 1)
			cout << x[cur] << ", ";
		else
			cout << x[cur] << '>';
		x.erase(x.begin() + cur);
		cur--;
	}
	return 0;
}