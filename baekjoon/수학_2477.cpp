// https://www.acmicpc.net/problem/2477

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, tmp1, tmp2;
	vector<int> case_vec, meter_vec, sync_vec;
	int max_i = 0, max_val = 0;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		cin >> tmp1 >> tmp2;
		case_vec.push_back(tmp1);
		meter_vec.push_back(tmp2);
	}
	for (int i = 0; i < 6; i++)
	{
		if (max_val < meter_vec[i] * meter_vec[(i + 1) % 6])
		{
			max_val = meter_vec[i] * meter_vec[(i + 1) % 6];
			max_i = i;
		}
	}
	answer = max_val - meter_vec[(max_i + 3) % 6] * meter_vec[(max_i + 4) % 6];
	answer *= n;
	cout << answer;
	return 0;
}