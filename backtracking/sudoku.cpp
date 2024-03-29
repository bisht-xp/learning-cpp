#include <iostream>

using namespace std;

bool isValidPosition(int arr[][20], int rowIndex, int colIndex, int num)
{
    for (int k = 0; k < 9; k++)
    {
        if (arr[rowIndex][k] == num)
        {
            return false;
        }
        if (arr[k][colIndex] == num)
        {
            return false;
        }
    }
    int subr = (rowIndex / 3) * 3;
    int subc = (colIndex / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[subr + i][subc + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int arr[][20], int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return sudoku(arr, i + 1, 0);
    }
    if (arr[i][j] != 0)
    {
        return sudoku(arr, i, j + 1);
    }
    for (int k = 1; k <= 9; k++)
    {
        if (isValidPosition(arr, i, j, k))
        {
            arr[i][j] = k;
            bool isSuccess = sudoku(arr, i, j + 1);
            if(isSuccess) {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}

int main()
{

    int arr[20][20] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 0},
    };

    bool val = sudoku(arr,0,0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}