//https://programmers.co.kr/learn/courses/30/lessons/70129


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(string s)
{
	vector<int> answer;
	int cnt = 0;
	int zero_cnt = 0;
	while (s.size()>1)
	{
		string tmp = "";

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0')
			{
				zero_cnt++;
				continue;
			}
			tmp += s[i];
		}
		int tmp_size = tmp.size();
		tmp = "";
		while (tmp_size > 0)
		{
			tmp += to_string(tmp_size % 2);
			tmp_size /= 2;
		}
		s = "";
		for (int i = tmp.size() - 1; i >= 0; i--)
			s += tmp[i];
		cnt++;
	}
	answer.push_back(cnt);
	answer.push_back(zero_cnt);
	return answer;
}

int main(void)
{
	string s1 = "110010101001", s2 = "01110", s3 = "1111111";
	vector<int> answer = solution(s3);
	cout << answer[0] << " " << answer[1];
	return 0;
}