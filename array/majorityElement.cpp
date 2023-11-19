#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int majorityElement(vector<int> &nums) {
    unordered_map<int, int> unMap;
    for(auto ele: nums) {
        unMap[ele]++;
    }
    int maxEle = -1;
    int ele;
    for(auto [first, second]: unMap) {
        if(maxEle < second) {
            maxEle = second;
            ele = first;
        }
    }

    return ele;
}


int main() {
    vector<int> arr = {2,2,1,1,1,2,2};
    int ele = majorityElement(arr);
    cout << ele << endl;
    return 0;
}