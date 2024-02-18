#include<vector>
#include<iostream>

using namespace std;

vector<int> countSort(vector<int> arr) {
    int n = arr.size();
    int largest = -1;
    for(int i=0; i<n;i++) {
        largest = max(largest, arr[i]);
    }
    vector<int> sorted(largest+1, 0);
    for(int &x: arr) {
        sorted[x]++;
    }
    int j=0;
    for(int i=0; i<largest+1; i++) {
        while(sorted[i]) {
            arr[j++] = i;
            sorted[i]--;
        }
    }
    return arr;
}

int main() {
    vector<int> v={3,4,99,5,1};
    vector<int> ans = countSort(v);
    for(int &i: ans) {
        cout << i << " ";
    }
    cout << endl;
        return 0;
}