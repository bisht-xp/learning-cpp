#include<iostream>
#include<vector>

using namespace std;

bool helper(int helpArr[][20], int i, int j, int n) {
    int r = i, c = j;
    //left-diagonal
    while(r>=0 && c >=0) {
        if(helpArr[r][c] == 1 ) {
            return false;
        }
        r--;
        c--;
    }
    //right-diagnal
    r=i, c=j;
    while(r>=0 && c < n) {
        if(helpArr[r][c] == 1 ) {
            return false;
        }
        r--;
        c++;
    }
    //check stright-top
    for(int k=0;k<i; k++) {
        if(helpArr[k][j] == 1) {
            return false;
        }
    }
    return true;

}

void printArr(int arr[][20], int n) {
    for(int i=0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

// bool nQueen(vector<vector<int>> &arr, int i, int n) {
//     if(i == n) {
//         printArr(arr);
//         return true;
//     }

//     for(int j=0; j<n; j++) {
//         if(helper(arr, i,j, n)) {
//             arr[i][j] = 1;
//             bool isSuccess =  nQueen(arr,i+1, n);
//             if(isSuccess) {
//                 return true;
//             }
//             arr[i][j] = 0;
//         }

//     }
//     return false;
// }

bool nQueen(int arr[][20], int i, int n) {
    if(i == n) {
        printArr(arr, n); // Assuming printArr is defined elsewhere
        return true;
    }

    for(int j = 0; j < n; j++) {
        if(helper(arr, i, j, n)) { 
            arr[i][j] = 1;
            bool isSuccess = nQueen(arr, i + 1, n);
            if(isSuccess) {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}


int main() {
    int arr[20][20]= {0};

    bool val = nQueen(arr, 0, 3);
    return 0;
}