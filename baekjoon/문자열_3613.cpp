//https://www.acmicpc.net/problem/3613


#include <iostream>
#include <string>
using namespace std;

string C2J(string bef)
{
	string after = "";
	for (int i = 0; i < bef.size(); i++)
	{
		if (bef[i] == '_')
		{
			after += bef[i + 1] - 32;
			i++;
		}
		else
		{
			after += bef[i];
		}
	}
	return after;
}

string J2C(string bef)
{
	string after = "";
	for (int i = 0; i < bef.size(); i++)
	{
		if (bef[i] >= 'A'&&bef[i] <= 'Z')
		{
			after += '_';
			after += (char)(bef[i] + 32);
		}
		else
		{
			after += bef[i];
		}
	}
	return after;
}

int main(void)
{
	string str;
	cin >> str;
	int c_cnt = 0, j_cnt = 0;
	bool java = false, c = false, unk = false;
	if (!(str[0]>='a' && str[0]<='z'))
	{
		unk = true;
	}
	if (str[str.size() - 1] == '_')
	{
		unk = true;
	}
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i - 1] == '_' && str[i] == '_')
			unk = true;
	}
	for (int i = 1; i < str.size(); i++)
	{
		if ((str[i] >= 'a'&&str[i] <= 'z') || str[i] == '_')
		{
			c_cnt++;
		}
		if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
		{
			j_cnt++;
		}

	}
	if (c_cnt == str.size() - 1)
		c = true;
	if (j_cnt == str.size() - 1)
	{
		java = true;
	}
	if (unk == true || (c == false && java == false))
	{
		cout << "Error!";
		return 0;
	}
	if (unk == false)
	{
		if (c == true && java == false)
		{
			cout << C2J(str);
		}
		else if (java == true && c == false)
		{
			cout << J2C(str);
		}
		if (c == true && java == true)
		{
			cout << str;
		}
	}
	return 0;
}