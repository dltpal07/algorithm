//https://www.acmicpc.net/problem/1992


#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> map;
string str="";
void divCon(int xs, int ys, int xe, int ye)
{
	int check = map[ys][xs];
	for (int i = ys; i < ye; i++)
	{
		for (int j = xs; j < xe; j++)
		{
			if (check == 0 && map[i][j] == 1)
			{
				check = 2;
			}
			else if (check == 1 && map[i][j] == 0)
			{
				check = 2;
			}
			if (check == 2)
			{
				str += '(';

				divCon(xs, ys, (xs + xe) / 2, (ys + ye) / 2);
				divCon((xs + xe) / 2, ys, xe, (ys + ye) / 2);
				divCon(xs, (ys + ye) / 2, (xs + xe) / 2, ye);
				divCon((xs + xe) / 2, (ys + ye) / 2, xe, ye);
				str += ')';
				return;
				
			}
		}
	}
	if (check == 0)
		str += '0';
	else if (check == 1)
		str += '1';
	return;
}


int main(void)
{
	int n;
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		vector<int> t;
		cin >> tmp;
		for (int i = 0; i < tmp.size(); i++)
		{
			t.push_back(tmp[i]-'0');
		}
		map.push_back(t);

	}
	
	divCon(0, 0, n, n);
	cout << str;
	return 0;
}