//https://www.acmicpc.net/problem/1002


#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int t,x1, y1, r1, x2, y2, r2 ;
	float dist = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1;
		}
		else if ((dist == r1+r2)||(dist == abs(r1-r2)))
		{
			cout << 1;
		}
		else if (r1+r2<dist || abs(r1-r2)>dist)
		{
			cout << 0;
		}
		else
		{
			cout << 2;
		}
		cout << "\n";
	}
	return 0;
}
