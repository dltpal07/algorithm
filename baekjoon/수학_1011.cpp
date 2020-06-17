//https://www.acmicpc.net/problem/1011


#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,x,y;
	cin >> t;
	for (int k = 0; k<t; k++)
	{
		long long i = 1;
		cin >> x >> y;
		while (i*i <= (y - x))
			i++;
		i--;
		long long remain = (y - x) - (i * i);
		remain = (long long)ceil((double)remain / (double)i);
		cout << i * 2 - 1 + remain << "\n";
	}
	return 0;
}
