#include <iostream>
#include <vector>

using namespace std;

void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }

vector<string> ratMaze(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector < vector < int >> vis(n, vector < int > (n, 0));
    vector<string> ans;
    findPathHelper(0, 0, mat, n, ans, "", vis);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,1,0},
                                 {1,1,0},
                                 {1,1,1},
                              };
    vector<string> ans = ratMaze(mat);
    for(string s: ans) {
        cout << s << ", ";
    }
    cout << endl;
    return 0;
}
