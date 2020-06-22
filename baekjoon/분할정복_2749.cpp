//https://www.acmicpc.net/problem/2749


#include <iostream>
#include <vector>
using namespace std;

long long a[1500000];
int divider = 1000000;

void Fibo() {
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i < 1500000; i++)
	{
		a[i] = (a[i - 1] + a[i - 2]) % divider;
	}
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	long long n;
	cin >> n;
	Fibo();
	cout << a[n % 1500000] << "\n";
	return 0;
}