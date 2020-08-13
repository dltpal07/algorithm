//https://www.acmicpc.net/problem/12791


#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
multimap<int, string> m;

void init()
{
	m.insert({ 1967, "DavidBowie" });
	m.insert({ 1969, "SpaceOddity" });
	m.insert({ 1970, "TheManWhoSoldTheWorld" });
	m.insert({ 1971, "HunkyDory" });
	m.insert({ 1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars" });
	m.insert({ 1973, "AladdinSane" });
	m.insert({ 1973, "PinUps" });
	m.insert({ 1974, "DiamondDogs" });
	m.insert({ 1975, "YoungAmericans" });
	m.insert({ 1976, "StationToStation" });
	m.insert({ 1977, "Low" });
	m.insert({ 1977, "Heroes" });
	m.insert({ 1979, "Lodger" });
	m.insert({ 1980, "ScaryMonstersAndSuperCreeps" });
	m.insert({ 1983, "LetsDance" });
	m.insert({ 1984, "Tonight" });
	m.insert({ 1987, "NeverLetMeDown" });
	m.insert({ 1993, "BlackTieWhiteNoise" });
	m.insert({ 1995, "1.Outside" });
	m.insert({ 1997, "Earthling" });
	m.insert({ 1999, "Hours" });
	m.insert({ 2002, "Heathen" });
	m.insert({ 2003, "Reality" });
	m.insert({ 2013, "TheNextDay" });
	m.insert({ 2016, "BlackStar" });


}

int main(void)
{
	int t, a, b;
	init();
	cin >> t;
	multimap<int, string>::iterator iter;
	while (t--)
	{
		cin >> a >> b;
		vector<pair<int, string>> answer;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->first >= a && iter->first <= b)
			{
				answer.push_back({ iter->first, iter->second });
			}
		}
		cout << answer.size() << endl;
		for (auto x : answer)
		{
			cout << x.first << " " << x.second << endl;
		}
	}

	return 0;
}



