//https://programmers.co.kr/learn/courses/30/lessons/72410


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string new_id)
{
	string answer = "";
	int i = 0;
	int stop = new_id.size();
	int cnt = 0;
	while (1)
	{
		i = 0;
		cnt = 0;
		while (i < stop)
		{
			if (i == 0 || i == new_id.size() - 1)
			{
				if (new_id[i] == '.')
				{
					cnt++;
					new_id.erase(new_id.begin() + i, new_id.begin() + i + 1);
					stop -= 1;
					continue;
				}
			}
			if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			{
				new_id[i] = tolower(new_id[i]);
			}
			if (i + 1 < stop)
			{
				if (new_id[i] == '.' && new_id[i + 1] == '.')
				{
					new_id.erase(new_id.begin() + i, new_id.begin() + i + 1);
					stop -= 1;
					continue;
				}
				
			}
			if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i]>='0' && new_id[i]<='9') ||
				new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			{
				i++;
				continue;

			}
			else
			{
				cnt++;
				new_id.erase(new_id.begin() + i, new_id.begin() + i + 1);
				stop -= 1;
			}
		}
		if (cnt == 0)
			break;
	}
	if (new_id.size() >= 16)
	{
		new_id = new_id.substr(0, 15);
		int stop = new_id.size() - 1;
		while (1)
		{
			if (new_id[stop] != '.')
				break;
			if (new_id[stop] == '.')
			{
				new_id.erase(new_id.begin() + stop, new_id.begin() + stop + 1);
				stop -= 1;
			}
		}
	}
	if (new_id.size() == 0)
		new_id = 'a';
	if (new_id.size() <= 2)
	{
		int last = new_id.size() - 1;
		for (int i = new_id.size(); i < 3; i++)
			new_id += new_id[last];
	}
	answer = new_id;
	return answer;
}

int main(void)
{
	string new_id1 = "...!@BaT#*..y.abcdefghijklm";
	string new_id2 = "z-+.^.", new_id3 = "=.=", new_id4 = "123_.def",
		new_id5 = "abcdefghijklmn.p";
	cout << solution(new_id5);
	return 0;
}