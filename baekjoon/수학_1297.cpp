//https://www.acmicpc.net/problem/1297


#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

	double diag, h, w, t, div;
	cin >> diag >> h >> w;
	t = pow(diag, 2);
	div = pow(h, 2) + pow(w, 2);
	t /= div;
	t = sqrt(t);
	
	cout << floor(t * h) << " " << floor(t * w);
	return 0;
}