#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> unMap;
    for(auto i: nums) {
        if(unMap[i]) {
            return true;
        } 
        unMap[i]++;
    }

    return false;
}


int main() {
    vector<int>arr = {1,2,3,4};
    if(containsDuplicate(arr)) {
        cout << "duplicate";
    } else {
        cout << "NO duplicate element";
    }

    return 0;
}