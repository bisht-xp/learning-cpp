#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
	unordered_map<char, int> map;
	if(s.length() != t.length()) {
		return false;
	}
	for (auto c : s)
	{
		map[c]++;
	}
	for (auto c : t)
	{
		if (!map[c])
		{
			return false;
		}
		map[c]--;	
	}

	return true;
}

int main()
{
	string s = "car";
	string t = "rat";
	cout << isAnagram(s, t) << endl;
	return 0;
}
