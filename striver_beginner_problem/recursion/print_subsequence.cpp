/*
Problem statement
Given a string 'S' of length 'N', return all the subsequences of the given string.

A subsequence is a sequence that can be derived from the given sequence by deleting
zero or more elements without changing the order of the remaining elements.

Note :
You may return the subsequences in any order but they will be printed in
lexicographically ascending order.

If a string from the returned array has a length of zero, it will be represented as 
'Empty String' in the output.

For Example:
For a given word “cn” the possible subsequences are 'Empty String', 'c', 'cn' and 'n'.

We get :
'Empty String' by deleting 'c' and 'n'.
'c' by deleting 'n'.
'n' by deleting 'c'.
'cn' if we don't delete any thing.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void helper(vector<int> s, vector<int> ans, vector<vector<int>> &str, int i) {
    if(i == s.size()) {
        str.push_back(ans);
        return;
    }
    ans.push_back(s[i]);
    helper(s, ans, str, i+1);
    ans.pop_back();
    helper(s, ans, str, i+1);
    return;
}

vector<vector<int>> generateSubsequences(vector<int> s){
    vector<vector<int>> str;
    helper(s, {}, str, 0);
    sort(str.begin(), str.end());
    return str;
}

int main() {
    vector<vector<int>> str = generateSubsequences({1,2,3});
    for(vector<int> s: str) {
        for(int x: s) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}