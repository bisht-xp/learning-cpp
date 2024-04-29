#include<iostream>
#include<vector>

using namespace std;

bool isPalindrom(string s, int start, int end) {

    while(start <= end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++, end--;
    }
    return true;
}

void helper(string s, vector<vector<string>> &ans, vector<string> &strs, int idx) {
    if(idx == s.length()) {
        // if(!strs.empty()) {
            ans.push_back(strs);
        // }
        return;
    }
    for(int i=idx; i<s.length(); i++) {
        if(isPalindrom(s, idx, i)) {
            strs.push_back(s.substr(idx, i-idx+1));
            helper(s,ans,strs,i+1);
            strs.pop_back();
        }
    }
    return;
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> strs;
    helper(s,ans,strs,0);
    return ans;
}


int main() {
    string s = "cdd";
    vector<vector<string>> ans = partition(s);
    for(vector<string> vec: ans) {
        for(string s: vec) {
            cout << s << ",";
        }
        cout << endl;
    }
    return 0;
}