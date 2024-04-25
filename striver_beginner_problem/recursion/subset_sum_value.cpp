#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void helper(vector<int> &arr, int i, int sum, vector<int> &ans) {
    if(i == arr.size()) {
        ans.push_back(sum);
        return;
    }

    sum += arr[i];
    helper(arr, i+1, sum, ans);
    sum -= arr[i];
    helper(arr, i+1, sum, ans);
    return;
}


vector<int> subsetSum(vector<int> &num){
  vector<int> ans;
  helper(num,0,0,ans);
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
    vector<int> vec = {1,2};
    vector<int> sum = subsetSum(vec);
    for(int s: sum) {
        cout << s << " ";
    }
    return 0;
}