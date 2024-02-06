#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
// #include<string>

using namespace std;

int main() {
    string strs[] = {"eat","tea","tan","ate","nat","bat"};
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> vec;
    int n= sizeof(strs)/sizeof(strs[0]);
    for (const string& s : strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        mp[sorted_s].push_back(s);
    }

    for(auto x: mp) {
        vec.push_back(x.second);
    }

    for(const auto &i: vec) {
        for(const auto &x: i) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}


