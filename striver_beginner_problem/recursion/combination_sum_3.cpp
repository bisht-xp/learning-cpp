#include<iostream>
#include<vector>

using namespace std;

// void helper(int k, int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &vec, int i) {
    
//     if(i == arr.size()) {
//         if(n == 0) {
//             if(vec.size() == k) {
//                 ans.push_back(vec);
//                 // return;
//             }
//         }
//         return;
//     }
    
//     if(n == 0) {
//         if(vec.size() == k) {
//             ans.push_back(vec);
//             return;
//         }
//     }

//     vec.push_back(arr[i]);
//     helper(k,n-arr[i], arr, ans, vec, i+1);
//     vec.pop_back();
//     helper(k,n, arr, ans, vec, i+1);

//     return;
// }

void helper(int k,int n, int start, vector<int>& vec, vector<vector<int>> &ans) {
   

    if(n==0 && k==vec.size()) {
        ans.push_back(vec);
        return;
    }

    for(int i=start; i<=9; i++) {
        if(i>n) {
            break;
        }
        vec.push_back(i);
        helper(k,n-i,i+1,vec,ans);
        vec.pop_back();
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    // vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    vector<int> vec;
    helper(k,n,1,vec,ans);
    return ans;
}

int main() {
    vector<vector<int>> ans = combinationSum3(3,9);
    for(vector<int> vec: ans) {
        for(int v: vec) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}