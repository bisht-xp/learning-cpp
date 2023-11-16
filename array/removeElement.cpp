#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    int k = 0;
    int i=0;
    int h = nums.size();
    //{0,1,2,2,3,0,4,2};
    if(nums.size() == 1 ) {  
        return 1;
    }
    while(i < h) {
        if(nums[i] == val) {
            while(nums[h-1] == val && i < h-1) {
                h--;
            }
            if(i >= h-1) {
                return i;
            }
            swap(nums[i], nums[h-1]);
        } 
        // k++;
        i++;
    }
    for(auto ele: nums) {
        cout << ele << " ";
    }

    cout << endl;
    return i;

}


int main() {
    // vector<int> nums = {3,2,2,3};
    // vector<int> nums = {0,1,2,2,3,0,4,2};
    // vector<int> nums = {3,3};
    vector<int> nums = {3};
    cout << removeElement(nums, 3) << endl;
    
    return 0;
}