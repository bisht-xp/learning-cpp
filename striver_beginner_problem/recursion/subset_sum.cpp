#include<iostream>
#include<vector>

using namespace std;

//Gives TLE
bool isHelper(int n, int k, vector<int> &arr, int i, int sum) {
    if(i==n) {
        if(sum == k) {
            return true;
        }
        return false;
    }
    sum+=arr[i];
    if(isHelper(n,k,arr,i+1, sum) == true) {
        return true;
    }
    sum -= arr[i];
    if(isHelper(n,k,arr,i+1, sum) == true) {
        return true;
    }
    return false;
}

// Dynmaic approch.
bool isSubsetPresent(int n, int k, vector<int> &a) {
    return isHelper(n,k,a,0,0);
}

int main() {
    vector<int> vec = {1,2,3};
    int n = vec.size();
    cout << isSubsetPresent(n,5,vec) << endl;
    return 0;
}