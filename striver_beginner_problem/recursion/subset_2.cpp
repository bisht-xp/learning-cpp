#include<iostream>
#include<vector>

using namespace std;


void helper(vector<int> &arr, vector<int> &vec, vector<vector<int>> &ans, int idx) {
        ans.push_back(vec);
    for(int i=idx; i<arr.size(); i++) {
        if(i != idx && arr[i] == arr[i-1]) continue;
        vec.push_back(arr[i]);
        helper(arr,vec,ans,i+1);
        vec.pop_back();
    }
    return;
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> vec;
    helper(nums,vec, ans,0);
    return ans;
}

int main() {
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(vector<int> vec: ans) {
        for(int v: vec) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}