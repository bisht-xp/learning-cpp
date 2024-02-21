#include<iostream>
#include<utility>

using namespace std;

pair<int,int> searchKey(int arr[][100], int key, int m, int n) {
    int i = 0, j = m-1;
    if(key<arr[0][0] && key>arr[n-1][m-1]) {
        return {-1,-1};
    }
    while(i <= n-1 && j>=0) {
        if(arr[i][j] == key) {
            return {i, j};
        }
        if(arr[i][j] < key) {
            i++;
        } else {
            j--;
        }
    }
    return {-1,-1};
}

int main() {
    int arr[100][100] = {{10,20,30,40},{15,25,35,45}, {17, 27, 37, 47}, {18,29, 39, 49}};
    pair<int,int> pr = searchKey(arr, 27, 4, 4);
    cout << pr.first << " "<<pr.second << endl;
    return 0;
}