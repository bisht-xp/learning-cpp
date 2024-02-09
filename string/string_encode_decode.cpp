#include <iostream>
#include <vector>

using namespace std;

string encode(vector<string> &strs)
{
    string s = "";
    for (auto &str : strs)
    {
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            char encodedChar = 'a' + (str[i] - 'a');
            s.push_back(encodedChar);
        }
        s.push_back(';');
    }
    return s;
}

vector<string> decode(string s){
    vector<string> str;
    int n = s.length();
    string st = "";
    for(int i=0; i<n; i++) {
        if(s[i] == ';') {
            str.push_back(st);
            st = "";
        }else {
            st += s[i];
        }
    }
    return str;
}

int main()
{
    // cout << 'b'-'a' << endl;
    vector<string> str = {"neet", "code", "love", "you"};
    string s = encode(str);
    vector<string> st = decode(s);
    cout << s << endl;
    for(auto x: st) {
        cout << x << " ";
    }
    return 0;
}