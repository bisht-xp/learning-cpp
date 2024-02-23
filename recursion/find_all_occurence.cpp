#include<iostream>
#include<vector>

using namespace std;

vector<int> func(int k, vector<int> v, int n) {
    vector<int> ans;
    if(n == v.size()) {
        return ans;
    }
    if(v[n] == k) { 
        ans.push_back(n);
    }
    vector<int> subArr = func(k,v, n+1);
    if(subArr.size() != 0) {
        ans.insert(ans.end(),subArr.begin(), subArr.end());
    }
    return ans;
}

vector<int> findAllOccurences(int k, vector<int> v){
    int n = v.size();
    vector<int> ans = func(k,v,0);
    return ans;
}

int main() {
    vector<int> v={1, 2, 1,3,1};
    vector<int> ans = findAllOccurences(1,v);
    for(int &i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}