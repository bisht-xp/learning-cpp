#include<iostream>
#include<vector>

using namespace std;

vector<int> mergeSortedArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> sortedArray;
    int i = 0, j =0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            sortedArray.push_back(arr1[i]);
            i++;
        } else if(arr1[i] >= arr2[j]) {
            sortedArray.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()) {
        sortedArray.push_back(arr1[i++]);
    }

    while(j < arr2.size()) {
        sortedArray.push_back(arr2[j++]);
    }

    return sortedArray;
}


int main() {
    vector<int> A {0,3,4,31};
    vector<int> B {4,6,30};
    vector<int> res;
    res = mergeSortedArray(A, B);
    for(auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}