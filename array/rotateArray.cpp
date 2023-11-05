#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotateArray(vector<int>& nums, int k) {
    reverse(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end()-k);
    // reverse(nums.begin()+k, nums.end());
    k = k%nums.size();
    int i=0;
    int high =  k;
    while(i < high-1) {
        int temp = nums[i];
        nums[i] = nums[high-1];
        nums[high-1] = temp;
        i++;
        high--;
    }
    high = nums.size();
    while(k < high-1) {
        int temp = nums[k];
        nums[k] = nums[high-1];
        nums[high-1] = temp;
        k++;
        high--;
    }

    for(auto i : nums) {
        cout << i << " ";
    }

}

int main() {
    // vector<int> arr = {1,2,3,4,5,6,7};
    vector<int> arr = {-1};
    rotateArray(arr, 2);
    return 0;   
}