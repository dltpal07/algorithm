//https://programmers.co.kr/learn/courses/30/lessons/17686


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> solution(vector<string> files)
{
	vector<string> answer;
	vector<string> str;
	vector<string> origin = files;
	priority_queue<pair<pair<string, int>, int>, vector<pair<pair<string, int>, int>>, greater<pair<pair<string, int>, int>>> pq;
	for (int i = 0; i < files.size(); i++)
	{
		// 소문자화
		transform(files[i].begin(), files[i].end(), files[i].begin(), ::tolower);
	}
	for (int i = 0; i < files.size(); i++)
	{
		string s1 = "", s2 = "", s3 = "";
		int idx = 0, num = 0;
		for (int j = 0; j < files[i].size(); j++)
		{
			if (!(files[i][j] >= '0' && files[i][j] <= '9'))
			{
				s1 += files[i][j];
			}
			else
			{
				idx = j;
				break;
			}
		}
		for (int j = idx; j < files[i].size(); j++)
		{
			if (s2.size()<5 && (files[i][j] >= '0' && files[i][j] <= '9'))
			{
				s2 += files[i][j];
			}
			else
			{
				idx = j;
				break;
			}
		}
		
		num = stoi(s2);
		pq.push({ { s1, num }, i });
		
	}
	while (!pq.empty())
	{
		answer.push_back(origin[pq.top().second]);
		pq.pop();
	}
	return answer;
}

int main(void)
{
	vector<string> str1 = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> str2 = { "F - 5 Freedom Fighter", "B - 50 Superfortress", "A - 10 Thunderbolt II", "F - 14 Tomcat" };
	vector<string> answer = solution(str2);
	for (auto x : answer)
	{
		cout << x << endl;
	}
	return 0;
}