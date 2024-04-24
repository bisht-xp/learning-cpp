#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void helper(vector<int> &arr, int target, vector<int> &vec, vector<vector<int>> &ans, int idx) {
    if(target == 0) {
        ans.push_back(vec);
        return;
    }

    for(int i=idx; i<arr.size(); i++) {
        if(i> idx && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) {
            break;
        }
        vec.push_back(arr[i]);
        helper(arr,target-arr[i],vec, ans, i+1);
        vec.pop_back();
    }
    return;
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> vec;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, vec, ans, 0);
    return ans;   
}

int main() {
    vector<int> v = {1,1,1,2,2};
    int target = 4;
    vector<vector<int>> vec = combinationSum2(v,target);
    for(vector<int> v: vec) {
        for(int i: v) {
            cout << i << ", "; 
        }
        cout << endl;
    }
}