#include<iostream>

using namespace std;

bool isValidPosition(int arr[][20], int x, int y, int n) {
    //column check
    // int i = x;
    for(int i=0; i<=x; i++) {
        if(arr[i][y] == 1) {
            return false;
        }
    }

    //left diagonal check
    int i=x, j = y;
    while(i>=0 && j>=0) {
        if(arr[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i=x, j=y;
    while(i>=0 && j<n ) {
        if(arr[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}


int nQueenWays(int arr[][20], int i,int n) {
    if(i == n) {
        return 1;
    }

    int ways = 0;
    for(int j=0; j<n; j++) {
        if(isValidPosition(arr,i,j,n)) {
            arr[i][j] = 1;
            ways += nQueenWays(arr,i+1, n);
            arr[i][j] = 0;
        }
    }
    return ways;
}


int main() {
    int arr[20][20]= {0};

    cout << nQueenWays(arr, 0, 4) << endl;
    return 0;
}