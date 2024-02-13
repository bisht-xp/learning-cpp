#include<iostream>
#include<vector>

using namespace std;

int lowerBound(vector<int> A, int val) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    int ans = -1;
    while(l <= h) {
        int mid = (l+h)/2;
        if(A[mid]<= val) {
            ans = A[mid];
        }
        if(A[mid] > val) {
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    return ans;
}


int main() {
    vector<int> v = {-1,-1,2,3,5};
    int ans = lowerBound(v, 5);
    cout << ans << endl;
    return 0;
}