#include<iostream>
#include<vector>

using namespace std;

bool isWordPresent(string str, vector<string> &dictionary) {
    for(string &s: dictionary) {
        if(str == s) {
            return true;
        }
    }
    return false;
}


int helper(string str, vector<string> &dictionary) {
    if(str.empty()) {
        return 1;
    }
    int way = 0;
    string s = "";
    for(int j=0; j<str.length(); j++) {
        s += str[j];
        if(isWordPresent(s,dictionary)) {
            way += helper(str.substr(j+1, str.length()), dictionary);
        }
    }

    return way;
}

int wordBreak(string str, vector<string> &dictionary){
	int strSize = str.length();
    return helper(str, dictionary);
}

int main() {
    vector<string> dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";

    cout << wordBreak(str, dictionary) << endl;
    return 0;
}