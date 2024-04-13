/*
** Problem statement
** You have been given an integer 'N'. Your task is to generate and return all 
** binary strings of length 'N' such that there are no consecutive 1's in the string.
** 
** A binary string is that string which contains only ‘0’ and ‘1’.
** 
** For Example:
** Let ‘N'=3, hence the length of the binary string would be 3.
** 
** We can have the following binary strings with no consecutive 1s:
** 000 001 010 100 101
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void helper(int n, vector<string> &str, string ans) {
    if(ans.length() == n) {
        str.push_back(ans);
        return;
    }

    if(ans.empty() || ans.back() == '0') {
        helper(n, str, ans+'0');
        helper(n, str, ans+'1');
    }else {
        helper(n, str, ans+'0');
    }

    return;
}

vector<string> generateString(int N) {
    vector<string> str;
    helper(N,str,"");
    return str;
}


int main() {
   
    vector<string> vec = generateString(4);
    for(string s: vec) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}