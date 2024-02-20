#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> mongoTree(char arr[][100], int n, int m)
{
    int ans[100][100];
    int x = 0;
    if (arr[0][0] == '#')
    {
        ans[0][0] = 1;
    }
    else
    {
        ans[0][0] = 0;
    }
    for (int j = 1; j < m; j++)
    {
        if (arr[0][j] == '#')
        {
            ans[0][j] = 1 + ans[0][j - 1];
        }
        else
        {
            ans[0][j] = ans[0][j - 1];
        }
    }
    for (int j = 1; j < m; j++)
    {
        if (arr[j][0] == '#')
        {
            ans[j][0] = 1 + ans[j - 1][0];
        }
        else
        {
            ans[j][0] = ans[j - 1][0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                ans[i][j] = 1+ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            }else {
                ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            }
            // vec[i].push_back()
        }
    }

    int s1 = 0, s2=0, s3 = 0, s4=0; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            s1 = ans[i][j];
            s2 = ans[i][m-1] - s1;
            s3 = ans[n-1][j] - s1;
            s4 = ans[n-1][m-1] -s1 -s2-s3;
            cout << "arr"<< i <<j << " :"<< s1 << " " << s2 << " " << s3 << " " << s4 <<endl;
        }
        cout << endl;
    }
    return {0,0};
}

int main()
{
    char arr[100][100] = {{'*','#','#','*'}, {'#','*','#','*'}, {'*','#','*','#'}, {'#','#','#','*'}};
    pair<int,int> pr = mongoTree(arr, 4, 4);
    cout << pr.first << " " << pr.second << endl;
    return 0;
}