//https://programmers.co.kr/learn/courses/30/lessons/17678


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";
	int st_time = 9 * 60;
	vector<int> num_table;
	for (int i = 0; i < timetable.size(); i++)
	{
		num_table.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
	}
	sort(num_table.begin(), num_table.end());
	int cnt = 0, idx = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		while (idx < num_table.size())
		{
			if (num_table[idx] <= st_time + t * i)
			{
				cnt++;
				idx++;
			}
			else
				break;
			if (cnt == m)
				break;
		}
		if (i == n - 1)
		{
			if (cnt == m)
				ans = num_table[idx - 1] - 1;
			else
				ans = st_time + t * i;
		}
		
	}
	if (to_string(ans / 60).size() == 1)
		answer += "0";
	answer += to_string(ans / 60);
	answer += ":";
	if (to_string(ans % 60).size() == 1)
		answer += "0";
	answer += to_string(ans % 60);
	return answer;
}

int main(void)
{
	int n1 = 1, t1 = 1, m1 = 5;
	int n2 = 2, t2 = 10, m2 = 2;
	int n3 = 2, t3 = 1, m3 = 2;
	int n4 = 1, t4 = 1, m4 = 5;
	int n5 = 1, t5 = 1, m5 = 1;
	int n6 = 10, t6 = 60, m6 = 45;
	vector<string> timetable1 = { "08:00", "08:01", "08:02", "08:03" };
	vector<string> timetable2 = { "09:10", "09:09", "08:00" };
	vector<string> timetable3 = { "09:00", "09:00", "09:00", "09:00" };
	vector<string> timetable4 = { "00:01", "00:01", "00:01", "00:01", "00:01" };
	vector<string> timetable5 = { "23:59" };
	vector<string> timetable6 = { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
	cout << solution(n1, t1, m1, timetable1)<<endl;
	cout << solution(n2, t2, m2, timetable2) << endl;
	cout << solution(n3, t3, m3, timetable3) << endl;
	cout << solution(n4, t4, m4, timetable4) << endl;

	cout << solution(n5, t5, m5, timetable5) << endl;
	cout << solution(n6, t6, m6, timetable6) << endl;

	return 0;
}