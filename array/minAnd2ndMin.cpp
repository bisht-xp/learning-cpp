#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> minAnd2ndMin(int a[], int n) {
    vector<int> vec;
    int min = a[0];
    int secondMin = INT_MAX;
    if(n < 1) {
        return {-1, -1};
    }

    for(int i=1; i<n; i++) {
        if(a[i] < min) {
            secondMin = min;
            min = a[i];
        }
        else if(a[i] < secondMin && a[i] > min) {
            secondMin = a[i];
        }
    cout << min << secondMin << endl;
    }
    
    if(secondMin == INT_MAX) {
        return {-1, -1};
    }
    
    return {min, secondMin};
}


int main () {
    int arr[] = {1,1,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vec;
    vec = minAnd2ndMin(arr, n);

    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}