#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int solve(vector<int> &nums){
    priority_queue<int, vector<int>, Compare> pq(nums.begin(), nums.end());
    int ans = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a+b;
        pq.push(sum);
        ans += sum;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << solve(nums) << endl;
    return 0;
}