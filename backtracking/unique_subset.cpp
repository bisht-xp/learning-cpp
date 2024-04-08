#include <iostream>
#include <vector>
#include <set>

using namespace std;

void helper(vector<int> &nums, vector<int> output, set<vector<int>> &ans, int i, int len)
{
    if (i == len)
    {
        ans.insert(output);
        return;
    }
    output.push_back(nums[i]);
    helper(nums, output, ans, i + 1, len);
    output.pop_back();
    helper(nums, output, ans, i + 1, len);
    return;
    // for(int j=0; j<len; j++) {
    //      helper(nums, output, ans, i+1, len);
    // // helper(nums, output, ans, i+1, len);
    // }
}

vector<vector<int>> uniqueSubsets(vector<int> nums)
{
    set<vector<int>> s;
    vector<int> output;
    vector<vector<int>> ans;
    helper(nums, output, s, 0, nums.size());
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> input = {1, 2, 2};
    vector<vector<int>> ans = uniqueSubsets(input);
    for (vector<int> vec : ans)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}