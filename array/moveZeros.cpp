#include<iostream>
#include<vector>

using namespace std;

void moiveZeroes(vector<int> &nums) {
    int initialPos = 0;
    bool isZero = false;
    int i = 0;
    while(i < nums.size()) {
        if(!isZero && nums[i] == 0) {
            initialPos = i;
            isZero = true;
        }
        else if(isZero && nums[i] != 0) {
            int temp = nums[initialPos];
            nums[initialPos] = nums[i];
            nums[i] = temp;
            initialPos++; 
        }
        i++;
    }
    for(auto i : nums) {
        cout << i << " ";
    }
    return;
}


int main() {
    vector<int> arr = {0};
    moiveZeroes(arr);
    return 0;
}