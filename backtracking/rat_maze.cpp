#include<iostream>
#include<vector>

using namespace std;

void helper(vector<string>& vecStr, vector<vector<int>> &arr,vector<vector<int>> &ans, int m, int n, int i, int j) {
    if( i== m-1 && j==n-1) {
        for(int k=0; k<m; k++) {
            for(int l=0; l<n; l++) {
                ans[k][l] = arr[k][l];
            }
            cout << endl;
        }
        return;
    }
    //downward
    if(i+1 < m && vecStr[i+1][j] != 'X' && arr[i+1][j] != 1) {
        arr[i+1][j] = 1;
        helper(vecStr, arr, ans, m,n,i+1, j);
        arr[i+1][j] = 0;
        // arr[i][j] = 0;
    }
    //left
    if(j+1 < n && vecStr[i][j+1] != 'X' && arr[i][j+1] != 1) {
        arr[i][j+1] = 1;
        helper(vecStr,arr,ans,m,n,i,j+1);
        arr[i][j+1] = 0;
    } 

    //right
    if(j > 0 && vecStr[i][j-1] != 'X' && arr[i][j-1] != 1) {
        arr[i][j-1] = 1;
        helper(vecStr,arr,ans,m,n,i,j-1);
        arr[i][j-1] = 0;
    } 

    //oviously 
    if(i >0  && vecStr[i-1][j] != 'X' && arr[i-1][j] != 1) {
        arr[i-1][j] = 1;
        helper(vecStr,arr,ans,m,n,i-1,j);
        arr[i-1][j] = 0;
    }
    
    return;
}
// vector<vector<int>> rateAndMice(vector<string> arr) {
vector<vector<int>> rateAndMice(vector<string> arr) {
    int m = arr.size();
    int n = arr[0].size();
    // vector<vector<int>> vec(0);
    vector < vector < int >> vec(m, vector < int > (n, 0));
    vector < vector < int >> ans(m, vector < int > (n, 0));
    vec[0][0] = 1;
    helper(arr, vec, ans,m,n,0,0);


    // for(int i=0; i<m; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}

int main() {
    vector<string> str = {"OXOO","OOOX","XOXO","XOOX","XXOO"};
    vector<vector<int>> vec = rateAndMice(str);
    //  vrateAndMice(str);
    for(vector<int> v: vec) {
        for(int i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}