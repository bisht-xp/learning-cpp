#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    return arr;
}


int main() {
    vector<int> v={3,4,2,5,1};
    vector<int> ans = bubbleSort(v);
    for(int &i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}