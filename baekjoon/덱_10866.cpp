//https://www.acmicpc.net/problem/10866


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int deque[10000] = { 0 };
int st = 0, ed = 0;
void push_front(int tmp)
{
	for (int i = ed + 1; i >= st+1; i--)
	{
		deque[i] = deque[i - 1];
	}
	deque[st] = tmp;
	ed++;
}

void push_back(int tmp)
{
	deque[ed] = tmp;
	ed++;
}

int pop_front()
{
	if (ed - st == 0)
		return -1;
	else
	{
		int tmp = deque[st];
		deque[st] = 0;
		st++;
		return tmp;
	}

}

int pop_back()
{
	if (ed - st == 0)
		return -1;
	else
	{
		int tmp = deque[ed-1];
		deque[ed-1] = 0;
		ed--;
		return tmp;
	}
}

int size()
{
	return ed - st;
}

int empty()
{
	if (ed - st == 0)
		return 1;
	else
		return 0;
}

int front()
{
	if (ed - st == 0)
		return -1;
	else
		return deque[st];
}

int back()
{
	if (ed - st == 0)
		return -1;
	else
		return deque[ed-1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	string str;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push_front")
		{
			cin >> tmp;
			push_front(tmp);
		}
		else if (str == "push_back")
		{
			cin >> tmp;
			push_back(tmp);
		}
		else if (str == "pop_front")
		{
			cout << pop_front() << "\n";
		}
		else if (str == "pop_back")
		{
			cout << pop_back() << "\n";
		}
		else if (str == "size")
		{
			cout << size()<<"\n";
		}
		else if (str == "empty")
		{
			cout << empty() << "\n";
		}
		else if (str == "front")
		{
			cout << front() << "\n";
		}
		else if (str == "back")
		{
			cout << back() << "\n";
		}
	}
	return 0;
}