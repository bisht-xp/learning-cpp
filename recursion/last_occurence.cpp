#include<iostream>
using namespace std;

int lastOccurence(int arr[], int n, int key) {
    if(n==0) {
        return -1;
    }
    int result = lastOccurence(arr+1, n-1, key);
    if(arr[0] == key && result == -1) {
        return 0;
    }
    if(result != -1)  {
        return result +1;
    }
    return -1;
}

int main() {
    int arr[] = {3,1,7,6,4,7,8};
    int n = sizeof(arr)/sizeof(int);
    cout << lastOccurence(arr,n,7);
    return 0;
}