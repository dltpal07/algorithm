//https://programmers.co.kr/learn/courses/30/lessons/12981


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;
	map<string, int> m;
	int a1 = 0, a2 = 0;
	for (int i = 0; i < words.size(); i++)
	{
		if (i>0 )
		{
			if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
			{
				a1 = (i + 1) % n;
				if (a1 == 0)
					a1 += n;
				a2 = (int)ceil((double)(i + 1) / (double)n);
				break;
			}
		}
		m[words[i]]++;
		if (m[words[i]] > 1)
		{
			a1 = (i + 1) % n;
			if (a1 == 0)
				a1 += n;
			a2 = (int)ceil((double)(i + 1) / (double)n);
			break;
		}
	}
	answer.push_back(a1);
	answer.push_back(a2);
	return answer;
}

int main(void)
{
	int n1 = 3, n2 = 5, n3 = 2;
	vector<string> words1 = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	vector<string> words2 = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
	vector<string> words3 = { "hello", "one", "even", "never", "now", "world", "draw" };
	vector<int> answer = solution(n3, words3);
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}