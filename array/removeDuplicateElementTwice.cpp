#include<iostream>
#include<vector>

using namespace std;

int removeDuplicateElement(vector<int>& nums) {
   int l = 1;
   int k = 1;
   for(int i=1; i<nums.size(); i++) {
    if(nums[l-1] == nums[i] && k < 2) {
        nums[l++] = nums[i];
        k++;
    }
    else if(nums[l-1] != nums[i]) {
        nums[l++] = nums[i];
        k=1;
    }
   }

   for(auto i: nums) {
    cout << i << " ";
   }
   cout << endl << l << endl;

   return l;

}

int main() {
    vector<int> arr = {0,0,1,1};
    int nonDuplicateElement = removeDuplicateElement(arr);
    return 0;
}