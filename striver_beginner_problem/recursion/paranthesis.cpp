#include<iostream>
#include<vector>

using namespace std;

void helper(int n, string s, vector<string> &str, int open, int close) {
    if(s.length() == n*2) {
        str.push_back(s);
        return;
    }

    if(s.empty() || open != n) {
        helper(n, s+"(", str, open+1, close);
    }
    if(close <open) {
        helper(n, s+")", str, open, close+1);
    }
}


vector<string> validParenthesis(int n){
    vector<string> str;
    helper(n,"",str,0,0);
    return str;
}

int main() {
    vector<string> str = validParenthesis(3);
    for(string s: str) {
        cout << s << endl;
    }
    return 0;
}