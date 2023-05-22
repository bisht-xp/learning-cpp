#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> unMap;

    for (int i = 0; i<s.length(); i++)
    {
        unMap[s[i]]++;
    }
    int i = 0;
    for(int i=0; i<s.length(); i++) {
        if(unMap[s[i]] == 1) return i;
    }

    return -1;
}

int main()
{
    string s = "anythingthatcanpasstothestring";
    cout << firstUniqChar(s) << endl;
    return 0;
}