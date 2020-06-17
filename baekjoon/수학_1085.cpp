//https://www.acmicpc.net/problem/1085


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int x, y, w, h, min_=987654321;
	vector<int> T(4);
	cin >> x >> y >> w >> h;
	T[0] = x;
	T[1] = y;
	T[2] = w - x;
	T[3] = h - y;
	min_ = *min_element(T.begin(), T.end());
	cout << min_;
	

	return 0;
}