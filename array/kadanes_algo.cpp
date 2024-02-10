#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int largestSubarraySum(vector<int>& v) {
    int sum = 0;
    int maxSum = INT_MIN;

    for(int i=0; i<v.size(); i++) {
        sum += v[i];
        if(sum<0) {
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    vector<int> v = {1,3,4,0,-1,-1,-2};
    cout << largestSubarraySum(v)<<endl;
    return 0;
}