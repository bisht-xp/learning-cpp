#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int maxSubArraySum(vector<int> &nums) {
    int maxSum  = INT_MIN;
    int sum = 0;
    for(auto i: nums) {
        sum += i;
        maxSum = max(maxSum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }

    return maxSum;
}


int main() {
    // vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> arr = {-3, -1};
    vector<int> arr = {-3, 0, -1};
    int maxSum = maxSubArraySum(arr);
    cout << maxSum << endl;
    return 0;
}
