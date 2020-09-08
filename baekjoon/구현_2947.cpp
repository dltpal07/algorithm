//https://www.acmicpc.net/problem/2947


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
	}
	while (1)
	{
		int flag = 0;
		for (int i = 0; i < 5; i++)
		{
			if (v[i] == i + 1)
				flag++;
		}
		if (flag == 5)
			break;
		for (int i = 0; i < 4; i++)
		{

			if (v[i] > v[i + 1])
			{
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				for (int i = 0; i < 5; i++)
				{
					cout << v[i] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}