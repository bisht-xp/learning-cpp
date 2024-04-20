#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int helper(string a, unordered_map<char, int> mp, int i, int count) {
    if(i == a.length()) {
        return count;
    }

    if(!mp[a[i]]) {
        mp[a[i]] = count;
        count *= 2;
        return helper(a, mp, i+1, count);
    } else {
        int temp = mp[a[i]];
        mp[a[i]] = count;
        count *= 2;
        count -= temp;
        return helper(a,mp,i+1,count);
    }
}

string moreSubsequence(int n, int m, string a, string b){
    unordered_map<char, int> mp;
    return helper(a,mp,0,1) >= helper(b,mp,0,1)? a: b;

}

int main() {
    cout << moreSubsequence(1,3,"f","eeg") << endl;
    return 0;
}