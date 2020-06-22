//https://www.acmicpc.net/problem/1920


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, x[100000];
void binarySearch(int n, int key)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while (end - start >= 0)
	{
		mid = (start + end) / 2;
		if (x[mid] == key)
		{
			cout << "1\n";
			return;
		}
		else if (x[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << "0\n";
	return;
}

int main(void)
{
	int tmp;
	bool isPrint = false;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	sort(x, x + n);
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> tmp;
		binarySearch(n, tmp);
	}
	
	return 0;
}