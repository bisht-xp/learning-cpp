#include<iostream>

using namespace std;

bool isValidPos(int arr[][20], int rowIndex, int colIndex, int n) {
    // checking of column
    for(int i=0; i<=rowIndex; i++) {
        if(arr[i][colIndex] == 1) 
            return false;
    }

    //checking for left-diagonal
    int i=rowIndex, j = colIndex;
    while(i>=0 && j>=0) {
        if(arr[i][j] == 1) return false;
        i--;
        j--;
    }

    //checking for right-diagonal
    i=rowIndex, j = colIndex;
    while(i>=0 && j<n) {
        if(arr[i][j] == 1) return false;

        i--;
        j++;
    }
    return true;
}


int numberOfWays(int arr[][20], int i, int n) {
    if(i==n) {
        return 1;
    }
    
    int ways = 0;
    for(int j=0; j<n; j++) {
        if(isValidPos(arr,i,j,n)) {
            arr[i][j] = 1;
            ways += numberOfWays(arr,i+1, n);
            arr[i][j] = 0;
        }
    }
    return ways;
}


int main() {
    int arr[20][20]= {0};
    cout << numberOfWays(arr, 0, 4) << endl;
    return 0;
}