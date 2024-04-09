#include <iostream>
#include <vector>

using namespace std;

bool isvalidChar(char ch, vector<vector<char>> &board, int i, int j, int m, int n) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return false;
    }
    return ch == board[i][j];
}
bool helper(vector<vector<char>> &board, string word, int i, int j, int m, int n) {
    if(word.empty()) {
        return true;
    }
    bool check = false;
    //left-side of the current position
    if(isvalidChar(word[0], board, i, j-1, m, n)) {
        check = helper(board, word.substr(1,word.length()), i, j-1, m, n);
    }
    //right-side of the current positon
    if(isvalidChar(word[0], board, i,j+1, m,n)) {
        check = helper(board, word.substr(1,word.length()), i, j+1, m, n);

    }
    //top-side of the current position
    if(isvalidChar(word[0], board, i-1, j, m, n)) {
        check = helper(board, word.substr(1,word.length()), i-1, j, m, n);
    }
    //obviously bottom side of the current position
    if(isvalidChar(word[0], board, i+1, j, m, n)) {
        check = helper(board, word.substr(1,word.length()), i+1, j, m, n);
    }
    return check;
}

bool wordSearch(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(word[0] == board[i][j]) {
                if(helper(board, word.substr(1,word.length()),i,j,m,n)) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A', 'D', 'E', 'E'},
    };
    cout << wordSearch(board, "SEE") << endl;
    return 0;
}