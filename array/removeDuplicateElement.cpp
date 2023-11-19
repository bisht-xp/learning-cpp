#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int removeDuplicateElement(vector<int>& nums) {
   int l = 1;
   for(int i=1; i<nums.size(); i++) {
    if(nums[l-1] != nums[i]) {
        nums[l++] = nums[i];
    }
   }

   return l;

}

int main() {
    vector<int> arr = {0};
    int nonDuplicateElement = removeDuplicateElement(arr);
    return 0;
}