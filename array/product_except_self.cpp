#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> prefix;
    vector<int> suffix(nums.size());
    int multi = 1;
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=0; i<nums.size()-1; i++) {
        multi *= nums[i];
        ans[i+1] *= multi;
    }
    multi = 1;

    for(int i=n-1; i>0; i--) {
        multi *= nums[i];
        ans[i-1] *= multi;
    }
    return ans;
}

int main() {
    vector<int> v = {1,2,3,4};
    vector<int> ans = productExceptSelf(v);
    for(auto &i: ans) {
        cout << i << " ";
    }
    return 0;
}