//https://programmers.co.kr/learn/courses/30/lessons/17682


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult)
{
	vector<int> num;
	int answer = 0;
	int n_size = 0;
	for (int i = 0; i < dartResult.size(); i++)
	{
		n_size = num.size();
		if (dartResult[i] >= '0' && dartResult[i] <= '9')
		{
			if (dartResult[i] == '1' && dartResult[i + 1] == '0')
			{
				num.push_back(10);
				i++;
			}
			else
			{
				num.push_back(dartResult[i] - '0');
			}
		}
		else if (dartResult[i] >= 'A' && dartResult[i] <= 'Z')
		{
			if (dartResult[i] == 'D')
				num[n_size - 1] = pow(num[n_size - 1], 2);

			else if(dartResult[i] == 'T')
				num[n_size - 1] = pow(num[n_size - 1], 3);

		}
		else
		{
			if (dartResult[i] == '*')
			{
				num[n_size - 1] *= 2;
				if (n_size - 2 >= 0)
					num[n_size - 2] *= 2;
			}
			if (dartResult[i] == '#')
			{
				num[n_size - 1] = -(num[n_size - 1]);
			}
		}
	}
	for (int i = 0; i < num.size(); i++)
	{
		answer += num[i];
	}
	return answer;
}

int main(void)
{
	string dartResult1 = "1S2D*3T", dartResult2 = "1D2S#10S", dartResult3 = "1D2S0T", dartResult4 = "1S*2T*3S";
	cout << solution(dartResult3);
	return 0;
}