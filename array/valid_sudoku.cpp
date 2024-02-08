#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_map<char, int> map;
    unordered_set<char> set;
    for (auto &i : board)
    {
        for (auto &j : i)
        {
            if (j != '.')
            {
                if (set.find(j) != set.end())
                {
                    return false;
                }
                set.insert(j);
            }
        }
        set.clear();
    }

    set.clear();

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.')
            {
                if (set.find(board[j][i]) != set.end())
                {
                    return false;
                }
                set.insert(board[j][i]);
            }
        }
        set.clear();
    }
    int x = 0, y = 0;
    while (x < 9)
    {
        while (y < 9)
        {
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    if (board[i][j] != '.')
                    {
                        if (set.find(board[i][j]) != set.end())
                        {
                            return false;
                        }
                        set.insert(board[i][j]);
                    }
                }
            }
            y += 3;
            set.clear();
        }
        y=0;
        x += 3;
    }
    return true;
}

int main()
{
    vector<vector<char>> ch{
    {'.', '.', '.', '.', '.', '.', '5', '.', '.'}, 
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
    {'9', '3', '.', '.', '2', '.', '4', '.', '.'}, 
    {'.', '.', '7', '.', '.', '.', '3', '.', '.'}, 
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
    {'.', '.', '.', '3', '4', '.', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.', '3', '.', '.', '.'}, 
    {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};

    cout << isValidSudoku(ch);

    return 0;
}