#include <iostream>
#include <vector>

using namespace std;

bool isvalidChar(char ch, vector<vector<char>> &board, int i, int j, int m, int n) {
    if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '!') {
        return false;
    }
    return ch == board[i][j];
}
bool helper(vector<vector<char>> &board, string word, int i, int j, int idx, int m, int n) {
   if(idx == word.length()) {
        return true;
   }

   if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx] ||  board[i][j] == '!') {
        return false;
    }

    char ch = board[i][j];
    board[i][j] = '!';
    bool top = helper(board,word,i-1,j,idx+1,m,n);
    bool right = helper(board,word,i,j+1,idx+1,m,n);
    bool bottom = helper(board,word,i+1,j,idx+1,m,n);
    bool left = helper(board,word,i,j-1,idx+1,m,n);
    board[i][j] = ch;
    return top||right||bottom||left;
}

bool wordSearch(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(word[0] == board[i][j]) {
                if(helper(board, word,i,j,0,m,n)) {
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
    cout << wordSearch(board, "ABCB") << endl;
    return 0;
}