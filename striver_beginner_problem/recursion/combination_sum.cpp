#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> &arr, int target, int sum, int i, vector<int> &vec, vector<vector<int>> &ans)
{
    if (i == arr.size())
    {
        return;
    }
    else if (sum == target)
    {

        ans.push_back(vec);
        return;
    }

    vec.push_back(arr[i]);
    sum += arr[i];
    if (sum <= target)
    {
        helper(arr, target, sum, i, vec, ans);
    }
    vec.pop_back();
    sum -= arr[i];
    helper(arr, target, sum, i + 1, vec, ans);
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    helper(candidates, target, 0, 0, v, ans);
    return ans;
}

int main()
{
    vector<int> v = {13, 3, 2, 17};
    vector<vector<int>> ans = combinationSum(v, 14);
    for (vector<int> vec : ans)
    {
        for (int i : vec)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}
