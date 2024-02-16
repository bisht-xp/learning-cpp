#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int main() {
    vector<int> v = {3,1,5,6,7,2,9,-1};
    int arr[] = {3,1,5,6,7,2,9,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(v.begin(), v.end(), compare);
    reverse(arr, arr+n);
    for(int &x: arr) {
        cout << x << " ";
    }
    cout << endl;
    for(int &x: v) {
        cout << x << " ";
    }
    return 0;
}