#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare (int a, int b) {
    return a > b;
}


int findKthLargestEle(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), compare);
    return nums[k-1];
}


int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << findKthLargestEle(nums, k) << endl;
    return 0;
}