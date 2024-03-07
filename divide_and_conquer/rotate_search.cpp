#include<iostream>
#include<vector>

using namespace std;

int rotateSearch(vector<int> v, int s, int e, int k) {
    if(s>e) {
        return -1;
    }
    int mid = (s+e)/2;
    if(v[mid] == k) {
        return mid;
    }
    if(v[s] <= v[mid]) {
        if(v[s] <= k and k <= v[mid]) {
            return rotateSearch(v,s,mid-1,k);
        }else {
            return rotateSearch(v,mid+1,e,k);
        }
    }else {
        if(v[mid] <= k and k <= v[e]) {
            return rotateSearch(v,mid+1,e,k);
        }else {
            return rotateSearch(v,s,mid-1,k);
        }
    }
    return -1;
}


int main() {
    vector<int> v = {5,6,7,9,1,2,3,4};
    int n = v.size();
    cout << rotateSearch(v,0,n-1,1) << endl;
    return 0;
}