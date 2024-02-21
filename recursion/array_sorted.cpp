#include<iostream>

using namespace std;

//backward direction 
bool isArraySorted(int arr[], int n) {
    if(n == 1) {
        return true;
    }

    bool isSorted = arr[n-1] > arr[n-2] && isArraySorted(arr, n-1);
    return isSorted;
}

bool isSorted(int arr[], int n) {
    if(n==1 || n==0) {
        return true;
    }
    if(arr[0] < arr[1] && isSorted(arr+1, n-1)) {
        return true;
    }

    return false;
} 



int main() {
    int arr[] = {1,2,3,4,6,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << isSorted(arr,n) << endl;
    return 0;
}
