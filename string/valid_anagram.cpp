#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/* bool isAnagram(string s, string t)
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
}*/

bool isAnagram(string s, string t) {
	vector<int> v(26,0);
	if(s.length() != t.length()) {
		return false;
	}
	for(auto c: s) {
		v[c-'a']++;
		v[c-'a']--;
	}
	for(auto i: v) {
		if(i != 0) {
			return false;
		}
	}
	return true;


}

int main()
{
	string s = "rat";
	string t = "car";
	cout << isAnagram(s, t) << endl;
	return 0;
}
