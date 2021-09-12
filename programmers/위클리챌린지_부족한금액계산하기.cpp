//https://programmers.co.kr/learn/courses/30/lessons/82612



#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
	unsigned long long answer = -1;
	unsigned long long total_money = 0;
	for (int i = 1; i <= count; i++)
	{
		total_money += (long long)price * (long long)i;
	}
	answer = (unsigned long long)total_money - (unsigned long long)money;
	if (total_money < money)
		return 0;
	return answer;
}

int main(void)
{
	int price = 3, money = 20, count = 4;
	cout << solution(price, money, count);
	return 0;
}