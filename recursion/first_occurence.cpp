#include<iostream>
#include<vector>

using namespace std;

int firstOccurence(int arr[], int n, int key) {
    if(n==0) {
        return -1;
    }
    if(arr[0] == key) {
        return 0;
    }
    int result =  firstOccurence(arr+1, n-1, key);
    if(result != -1) {
        return result + 1;
    }
    return -1;
}


int main() {
    int arr[] = {3,1,5,7,4,9,8};
    int n = sizeof(arr)/sizeof(int);
    cout << firstOccurence(arr,n,7);
    return 0;
}