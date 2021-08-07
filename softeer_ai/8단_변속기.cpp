//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=408

#include <iostream>

using namespace std;

int nums[8];

int main(void)
{
	int asc = 0, des = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> nums[i];
		if (i > 0)
		{
			if (nums[i - 1] - nums[i] == 1)
			{
				des++;
			}
			else if (nums[i] - nums[i-1] == 1)
			{
				asc++;
			}
		}
	}
	if (des == 7)
	{
		cout << "descending";
	}
	else if (asc == 7)
	{
		cout << "ascending";
	}
	else
	{
		cout << "mixed";
	}
	return 0;
}