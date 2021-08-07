//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=395


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int W, n, m, p, all_kg = 0, answer=0;
	vector<pair<int, int>> v;
	cin >> W >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> tmp;
		cin >> m >> p;
		tmp.first = p;
		tmp.second = m;
		v.push_back(tmp); 
	}
	sort(v.begin(), v.end(), greater<>());
	for (auto x:v)
	{
		if (all_kg == W)
			break;
		if (all_kg + x.second > W)
		{
			x.second = W - all_kg;
		}
		all_kg += x.second;
		answer += x.second * x.first;
	}
	cout << answer;
	return 0;
}