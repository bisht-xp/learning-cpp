#include<iostream>
#include<vector>

using namespace std;

bool isValid(int i, int j, int n, vector<vector<int>> &board) {
    // check staright 
    for(int k=0; k<=i; k++) {
        if(board[k][j] == 1) {
            return false;
        }
    }
    // check left diagonal
    int row = i, col = j;
    while(row >= 0 && col >= 0) {
        if(board[row--][col--] == 1) {
            return false;
        }
    }

    //right diagonal
    row = i, col = j;
    while(row >= 0 && col < n) {
        if(board[row--][col++] == 1) {
            return false;
        }
    }
    return true;
}

void helper(int n, int i, vector<vector<int>> &ans, vector<int> &board, vector<vector<int>> &temp) {
    if(i==n) {
        ans.push_back(board);
        return;
    }

    for(int j=0; j<n; j++) {
        if(isValid(i,j,n,temp)) {
            temp[i][j] = 1;
            board[i*n+j] = 1;
            helper(n,i+1,ans,board, temp);
            temp[i][j] = 0;
            board[i*n+j] = 0;
        }
    }
    return;
}
// void helper(int n, int i, vector<vector<string>> &ans, vector<string> &board) {
//     if(i==n) {
//         ans.push_back(board);
//         return;
//     }

//     for(int j=0; j<n; j++) {
//         if(isValid(i,j,n,board)) {
//             board[i][j] = 'Q';
//             helper(n,i+1,ans,board);
//             board[i][j] = '.';
//         }
//     }
//     return;
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector < string > board(n);
//     vector<vector<string>> ans;
//     string s(n, '.');
//     for (int i = 0; i < n; i++) {
//         board[i] = s;
//     }
//     helper(n,0,ans,board);
//     return ans;
// }

vector<vector<int>> nQueens(int n)
{
    vector<int> board(n*n, 0);
    vector<vector<int>> ans;
    vector<vector<int>> temp(n);
    vector<int> arr(n,0);
    for(int i=0; i<n; i++) {
        temp[i] = arr;
    }
    helper(n,0,ans,board, temp);
    return ans;
}

int main() {
    vector<vector<int>> ans = nQueens(4);
    // vector<vector<string>> ans = solveNQueens(4);

    for(vector<int> str: ans) {
        for(int s: str) {
            cout << s << ", ";
        }
    }
    return 0;
}