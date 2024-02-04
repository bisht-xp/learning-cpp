#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++) {
        if(mp[target-nums[i]]) {
            return {mp[target-nums[i]]-1, i};
        }
        mp[nums[i]] = i+1;
    }
    for(auto m: mp) {
        cout << m.second << " ";

    }
    cout << endl;
    return {0, 0};
}

int main() {
    vector<int> v={2,7,11,15};
    vector<int> ans = twoSum(v, 9);
    for(auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}